#include"Icosphere.h"
using std::vector;
using std::cout;

Icosphere::Icosphere(float radiusP, int subdivisionP, bool smoothP):
radius {radiusP}, subdivision{ subdivisionP}, smooth{smoothP}{

}

///////////////////////////////////////////////////////////////////////////////
// compute 12 vertices of icosahedron using spherical coordinates
// The north pole is at (0, 0, r) and the south pole is at (0,0,-r).
// 5 vertices are placed by rotating 72 deg at elevation 26.57 deg (=atan(1/2))
// 5 vertices are placed by rotating 72 deg at elevation -26.57 deg
///////////////////////////////////////////////////////////////////////////////
vector<float> Icosphere::computeIcosahedronVertices(){
    

    const float PI = acos(-1);// PI aproximation
    const float horizontalAngle = PI / 180 * 72; // that permit to convert 72 deg in radiant 1.256
    const float verticalAngle = atanf(1.0f/2); //elevation = 26.565 degres or 0.46 rad

    vector<float> mVertices(12 * 3);
    int i1, i2; 
    float z, xy;
    float hAngle1 = -PI/2 - horizontalAngle/2; // start from -126 degres at 1st row
    float hAngle2 = -PI/2; // start from -90 degres at 2nd row


    // the first top vertex (0, 0, r)
    mVertices[0] = 0;
    mVertices[1] = 0;
    mVertices[2] = radius;

    //Other 10 Vertices 2nd an 3rd rows

    for(int i = 1; i<= 5 ; i++){
        i1 = i*3;        // for the 2nd row
        i2 = (i+5)*3;    // for the 3rd row

        z = radius * sinf(verticalAngle); // elevation
        xy= radius * cosf(verticalAngle); // lenght on xy plan

        mVertices[i1]=xy * cosf(hAngle1);   //  x
        mVertices[i2]= xy * cosf(hAngle2);
        mVertices[i1 + 1] = xy * sinf(hAngle1);  // y
        mVertices[i2 + 1] = xy * sinf(hAngle2);
        mVertices[i1 + 2] = z;                   // z
        mVertices[i2 + 2] = -z;

        // next horizontal angle
        hAngle1 += horizontalAngle;
        hAngle2 += horizontalAngle;


    }
    // the last bottom vertex (0, 0, -r)
    i1 = 11*3;
    mVertices[i1] = 0;
    mVertices[i1 + 1] = 0;
    mVertices[i1 + 2] = -radius;

    vertices = mVertices;

    return mVertices;

}

void Icosphere::computeHalfVertex(const float v1[3], const float v2[3], float length, float newV[3])
{
    newV[0] = v1[0] + v2[0];
    newV[1] = v1[1] + v2[1];
    newV[2] = v1[2] + v2[2];
    float scale = Icosphere::computeScaleForLength(newV, length);
    newV[0] *= scale;
    newV[1] *= scale;
    newV[2] *= scale;
}
float Icosphere::computeScaleForLength(const float v[3], float length)
{
    // and normalize the vector then re-scale to new radius
    return length / sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
void Icosphere::displayvertices(vector<float> verticesP){
for(auto i = verticesP.begin(); i!= verticesP.end();i++){
    cout<<*i<<'\n';
    }
}
// this function is WIP
/*void Icosphere::subdivideVerticesFlat(){
    vector<float> tmpVertices;
    vector<unsigned int> tmpIndices;
    int indexCount;
    const float *v1, *v2, *v3;
    float newV1[3], newV2[3], newV3[3];
    unsigned int index {0};
    

    //iteration
   for (int i=1; i<= subdivision; i++){

        //copy prev array
        tmpVertices = vertices;
        tmpIndices = indices;


        //clear prev arrays

        vertices.clear();
        indices.clear();

        index = 0;
        indexCount = (int)tmpIndices.size();
        // j+=3 beacuse all point have 3 coordonate (x,y,z) and increment on each point
        for(int j = 0 ;j < indexCount; j+=3){

            //get 3 vertice of a triangle
            v1 =&tmpVertices[tmpIndices[j]*3];
            v2 =&tmpVertices[tmpIndices[j+1]*3];
            v3 =&tmpVertices[tmpIndices[j+2]*3];

            //get 3 new verticesby splitting half on each edge
            computeHalfVertex(v1, v2, radius, newV1);
            computeHalfVertex(v2, v3, radius, newV2);
            computeHalfVertex(v1, v3, radius, newV3);

            // add 4 new triangles
            addTriangle(v1, newV1, newV3);
            addIndices(index, index+1, index+2);

            addTriangle(newV1, v2, newV2);
            addIndices(index+3, index+4, index+5);

            addTriangle(newV1, newV2, newV3);
            addIndices(index+6, index+7, index+8);

            addTriangle(newV3, newV2, v3);
            addIndices(index+9, index+10, index+11);
        }


    }
}*/
