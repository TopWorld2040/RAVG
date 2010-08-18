#version 400
#extension GL_NV_gpu_shader5 : enable
#extension GL_EXT_shader_image_load_store : enable
#extension GL_NV_shader_buffer_load : enable

uniform float* ptrCellStreams;
uniform layout( size1x32 ) image2DArray imgCellStreams;
uniform layout( size1x32 ) iimage2DArray imgCellCounters;
uniform vec2 cellSize;
uniform ivec2 gridSize;
uniform vec2 gridOrigin;

smooth in vec2 f_tex;

out vec4 out_color;

int streamIndex = 0;
ivec2 gridCoord;

void lineIntersectionY (vec2 l0, vec2 l1, float y, float minX, float maxX,
                        out bool found, out float x);

void quadIntersectionY (vec2 q0, vec2 q1, vec2 q2, float y, float minX, float maxX,
                        out bool found1, out bool found2, out float x1, out float x2);

float nextStreamToken ()
{
  float streamToken = ptrCellStreams[ streamIndex ];
  streamIndex++;
  return streamToken;
}

void main (void)
{
  vec3 finalColor = vec3( 1,1,1 );
  vec4 objColor = vec4( 0,0,0,0 );
  bool objValid = false;
  int objWinding = 0;

  //Find grid coordinate and pivot
  gridCoord = ivec2(floor( (f_tex - gridOrigin) / cellSize ));
  vec2 pivot = gridOrigin + (vec2(gridCoord) + vec2(0.5,0.5)) * cellSize;

  //Check if coordinate in range
  if (gridCoord.x >= 0 && gridCoord.x < gridSize.x &&
      gridCoord.y >= 0 && gridCoord.y < gridSize.y)
  {
    //Find cell bounds
    vec2 cmin = vec2(
      gridOrigin.x + gridCoord.x * cellSize.x,
      gridOrigin.y + gridCoord.y * cellSize.y );

    vec2 cmax = vec2(
      gridOrigin.x + (gridCoord.x + 1.0f) * cellSize.x,
      gridOrigin.y + (gridCoord.y + 1.0f) * cellSize.y );

    //Init stream index
    vec4 cellCounterTexel1 = imageLoad( imgCellCounters, ivec3( gridCoord, 1 ) );
    streamIndex = int( cellCounterTexel1.r );

    //Loop until end of stream
    int safetyCounter = 0;
    while (streamIndex != -1)
    {
      if (++safetyCounter == 10000) { finalColor = vec3(1,0,0); break; }
      int segType = (int) nextStreamToken();

      if (segType == 1)
      {
        vec2 l0 = vec2( nextStreamToken(), nextStreamToken() );
        vec2 l1 = vec2( nextStreamToken(), nextStreamToken() );
        
        bool found; float xx;
        vec2 pp = clamp( (f_tex - cmin) / cellSize, vec2(0), vec2(1) );
        lineIntersectionY( l0,l1, pp.y, pp.x, 1.0, found, xx );
        if (found) objWinding++;
      }
      else if (segType == 2)
      {
        vec2 q0 = vec2( nextStreamToken(), nextStreamToken() );
        vec2 q1 = vec2( nextStreamToken(), nextStreamToken() );
        vec2 q2 = vec2( nextStreamToken(), nextStreamToken() );

        bool found1, found2; float xx1,xx2;
        vec2 pp = clamp( (f_tex - cmin) / cellSize, vec2(0), vec2(1) );
        quadIntersectionY( q0,q1,q2, pp.y, pp.x, 1.0, found1,found2, xx1,xx2 );
        if (found1) objWinding++;
        if (found2) objWinding++;
      }
      else if (segType == 3)
      {
        //Finalize previous object
        if (objValid)
          if (objWinding % 2 == 1)
            finalColor = objColor.rgb;

        //Get color of the next object
        objColor = vec4( nextStreamToken(), nextStreamToken(), nextStreamToken(), nextStreamToken() );
        objValid = true;
        objWinding = 0;
      }
      else break;

      streamIndex = (int) nextStreamToken();
    }
  }

  //Finalize previous object
  if (objValid)
    if (objWinding % 2 == 1)
      finalColor = objColor.rgb;

  out_color = vec4( finalColor, 1 );
}

void lineIntersectionY (vec2 l0, vec2 l1, float y, float minX, float maxX,
                        out bool found, out float x)
{
  found = false;

  //Linear equation (0 = a*t + b)
  float a = l1.y - l0.y;
  float b = l0.y - y;

  //Check if equation constant
  if (a != 0.0)
  {
    //Find t of intersection
    float t = -b / a;

    //Plug into linear equation to find x of intersection
    if (t >= 0.0 && t <= 1.0) {
      x = l0.x + t * (l1.x - l0.x);
      if (x >= minX && x <= maxX) found = true;
    }
  }
}

void quadIntersectionY (vec2 q0, vec2 q1, vec2 q2, float y, float minX, float maxX,
                        out bool found1, out bool found2, out float x1, out float x2)
{
  found1 = false;
  found2 = false;

  //Quadratic equation (0 = a*t*t + b*t + c)
  float a = (q0.y - 2*q1.y + q2.y);
  float b = (-2*q0.y + 2*q1.y);
  float c = q0.y - y;

  //Discriminant
  float d = b*b - 4*a*c;

  //Find roots
  if (d > 0.0) {

    float t1,t2;

    //Find t of intersection
    if (a == 0.0)
    {
      //Equation is linear
      t1 = (y - q0.y) / (q2.y - q0.y);
      t2 = -1.0;
    }
    else
    {
      //Equation is quadratic
      float sd = sqrt( d );
      t1 = (-b - sd) / (2*a);
      t2 = (-b + sd) / (2*a);
    }
    
    //Plug into bezier equation to find x of intersection
    if (t1 >= 0.0 && t1 <= 1.0) {
      float t = t1;
      float one_t = 1.0 - t;
      x1 = one_t*one_t * q0.x + 2*t*one_t * q1.x + t*t * q2.x;
      if (x1 >= minX && x1 <= maxX) found1 = true;
    }

    if (t2 >= 0.0 && t2 <= 1.0) {
      float t = t2;
      float one_t = 1.0 - t;
      x2 = one_t*one_t * q0.x + 2*t*one_t * q1.x + t*t * q2.x;
      if (x2 >= minX && x2 <= maxX) found2 = true;
    }
  }
}
