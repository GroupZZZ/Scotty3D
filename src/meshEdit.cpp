#include <float.h>
#include <assert.h>
#include "meshEdit.h"
#include "mutablePriorityQueue.h"
#include "error_dialog.h"

namespace CMU462 {

    VertexIter HalfedgeMesh::splitEdge(EdgeIter e0) {
        // TODO: (meshEdit)
        // This method should split the given edge and return an iterator to the
        // newly inserted vertex. The halfedge of this vertex should point along
        // the edge that was split, rather than the new edges.

        HalfedgeIter h0 = e0->halfedge();
        HalfedgeIter h1 = h0->next();
        HalfedgeIter h2 = h1->next();
        HalfedgeIter h3 = h0->twin();
        HalfedgeIter h4 = h3->next();
        HalfedgeIter h5 = h4->next();
        HalfedgeIter h6 = h1->twin();
        HalfedgeIter h7 = h2->twin();
        HalfedgeIter h8 = h4->twin();
        HalfedgeIter h9 = h5->twin();

        // VERTICES
        VertexIter v0 = h0->vertex();
        VertexIter v1 = h3->vertex();
        VertexIter v2 = h8->vertex();
        VertexIter v3 = h6->vertex();
        // ...you fill in the rest!...

        // EDGES
        EdgeIter e1 = h5->edge();
        EdgeIter e2 = h4->edge();
        EdgeIter e3 = h2->edge();
        EdgeIter e4 = h1->edge();

        // ...you fill in the rest!...

        // FACES
        FaceIter f0 = h0->face();
        FaceIter f1 = h3->face();

        HalfedgeIter h10 = newHalfedge();
        HalfedgeIter h11 = newHalfedge();
        HalfedgeIter h12 = newHalfedge();
        HalfedgeIter h13 = newHalfedge();
        HalfedgeIter h14 = newHalfedge();
        HalfedgeIter h15 = newHalfedge();

        EdgeIter e5 = newEdge();
        EdgeIter e6 = newEdge();
        EdgeIter e7 = newEdge();

        FaceIter f2 = newFace();
        FaceIter f3 = newFace();

        VertexIter vN = newVertex();
        vN->position = e0->centroid();

        h0->next() = h1;
        h0->twin() = h3;
        h0->vertex() = vN;
        h0->edge() = e0;
        h0->face() = f0;

        h1->next() = h10;
        h1->twin() = h6;
        h1->vertex() = v1;
        h1->edge() = e4;
        h1->face() = f0;

        h10->next() = h0;
        h10->twin() = h11;
        h10->vertex() = v3;
        h10->edge() = e6;
        h10->face() = f0;


        h3->next() = h12;
        h3->twin() = h0;
        h3->vertex() = v1;
        h3->edge() = e0;
        h3->face() = f1;
        
        h12->next() = h5;
        h12->twin() = h13;
        h12->vertex() = vN;
        h12->edge() = e7;
        h12->face() = f1;

        h5->next() = h3;
        h5->twin() = h9;
        h5->vertex() = v2;
        h5->edge() = e1;
        h5->face() = f1;

        h11->next() = h2;
        h11->twin() = h10;
        h11->vertex() = vN;
        h11->edge() = e6;
        h11->face() = f2;

        h2->next() = h14;
        h2->twin() = h7;
        h2->vertex() = v3;
        h2->edge() = e3;
        h2->face() = f2;

        h14->next() = h11;
        h14->twin() = h15;
        h14->vertex() = v0;
        h14->edge() = e5;
        h14->face() = f2;

        h15->next() = h4;
        h15->twin() = h14;
        h15->vertex() = vN;
        h15->edge() = e5;
        h15->face() = f3;

        h4->next() = h13;
        h4->twin() = h8;
        h4->vertex() = v0;
        h4->edge() = e2;
        h4->face() = f3;

        h13->next() = h15;
        h13->twin() = h12;
        h13->vertex() = v2;
        h13->edge() = e7;
        h13->face() = f3;

        e0->halfedge() = h0;
        e6->halfedge() = h10;
        e5->halfedge() = h14;
        e7->halfedge() = h12;

        vN->halfedge() = h0;

        f0->halfedge() = h1;
        f1->halfedge() = h5;
        f2->halfedge() = h11;
        f3->halfedge() = h4;

        showError("splitEdge() not implemented.");
        return vN;
    }

/*VertexIter HalfedgeMesh::collapseEdge(EdgeIter e) {
    // TODO: (meshEdit)
    // This method should collapse the given edge and return an iterator to
    // the new vertex created by the collapse.
    HalfedgeIter h0 = e->halfedge();
    HalfedgeIter h1 = h0->next();
    HalfedgeIter h2 = h1->next();
    HalfedgeIter h3 = h0->twin();
    HalfedgeIter h4 = h3->next();
    HalfedgeIter h5 = h4->next();
    HalfedgeIter h6 = h1->twin();
    HalfedgeIter h7 = h2->twin();
    HalfedgeIter h8 = h4->twin();
    HalfedgeIter h9 = h5->twin();

    // VERTICES
    VertexIter v0 = h0->vertex();
    VertexIter v1 = h3->vertex();
    VertexIter v2 = h8->vertex();
    VertexIter v3 = h6->vertex();
    // ...you fill in the rest!...

    // EDGES
    EdgeIter e1 = h5->edge();
    EdgeIter e2 = h4->edge();
    EdgeIter e3 = h2->edge();
    EdgeIter e4 = h1->edge();

    // ...you fill in the rest!...

    // FACES
    FaceIter f0 = h0->face();
    FaceIter f1 = h3->face();



    //HalfedgeIter h0 = e->halfedge();
    //get all the point related to h0;
    VertexIter p0 = h0->vertex();
    HalfedgeIter leftHalfedgeModify;
    HalfedgeIter rightHalfedgeModify;
    FaceIter leftFaceModify;
    FaceIter rightFaceModify;
    int countleft=0, countright = 0;
    //分两组，分别判断每一组的数量
    for (HalfedgeIter i = h0->next(); p0 != i->vertex(); i = i->next()) {
        ++countleft;
        if (i->next()->vertex() == p0) {//last point in the sequence. should connect to p0
            leftHalfedgeModify = i;
        }

    }
    VertexIter p1 = h0->twin()->vertex();
    for (HalfedgeIter i = h0->twin()->next(); p1 != i->vertex(); i = i->next()) {
        ++countright;
        if (i->next()->vertex() == p1) {
            rightHalfedgeModify = i;
        }
    }
    leftFaceModify = h0->face();
    rightFaceModify = h0->twin()->face();
    if (countleft == 2) {//face will collapse,
        h6->next() = h6->next();
        h6->twin() = h7;
        h6->vertex() = v3;
        h6->edge() = e4;
        h6->face() = h6->face();
        h7->next() = h7->next();
        h7->twin() = h6;
        h7->vertex() = v1;
        h7->edge() = e4;
        h7->face() = h7->face();

        deleteHalfedge(h1);
        deleteHalfedge(h2);
    //    deleteHalfedge(h0);
        deleteEdge(e3);
        deleteFace(f0);
    }
    else {
        leftHalfedgeModify->next() = h0->next();
        leftHalfedgeModify->twin()->vertex() = p1;
        h0->face()->halfedge() = h0->next();//incase the face is refering the deleted halfedge
    }
    if (countright == 2) {
        h8->next() = h8->next();
        h8->twin() = h9;
        h8->vertex() = v2;
        h8->edge() = e1;
        h8->face() = h8->face();
        h9->next() = h9->next();
        h9->twin() = h8;
        h9->vertex() = v1;
        h9->edge() = e1;
        h9->face() = h9->face();
        
    //    deleteHalfedge(h3);
        deleteHalfedge(h4);
        deleteHalfedge(h5);
        deleteEdge(e2);
        deleteFace(f1);
    }
    else {
        rightHalfedgeModify->next() = h0->twin()->next();//change half edge
        h0->twin()->next()->vertex() = p1;
        h0->twin()->face()->halfedge() = h0->twin()->next();
    }
    p1->position = (p0->position + p1->position) / 2;
    
    deleteEdge(e);
    deleteHalfedge(h0);
    deleteHalfedge(h3);
    
    //showError("collapseEdge() not implemented.");
    return v1;
    
}*/
VertexIter HalfedgeMesh::collapseEdge(EdgeIter e) {

    // TODO: (meshEdit)
    // This method should collapse the given edge and return an iterator to
    // the new vertex created by the collapse.

    auto vt1 = e->halfedge()->vertex();
    auto vt2 = e->halfedge()->twin()->vertex();

    // get intersection of the one ring of vt1 and vt2
    int num_one_ring_shared_adjacent_verts = 0;



    auto h = e->halfedge();
    auto h_twin = h->twin();
    auto newVtx = h->vertex();
    auto delVtx = h_twin->vertex();

    auto h1 = e->halfedge()->next();
    auto h2 = e->halfedge()->twin()->next();
    auto h1_twin = h1->twin();
    auto h2_twin = h2->twin();
    auto h1_prev = h1;
    do {
        h1_prev = h1_prev->next();
    } while (h1_prev->next() != h);
    auto h2_prev = h2;
    do {
        h2_prev = h2_prev->next();
    } while (h2_prev->next() != h_twin);

    // Triangular cases
    if (h1->next() == h1_prev) {
        // printf("First!\n");
        auto e1 = h1->edge();
        auto f1 = h1->face();
        auto v1 = h1->vertex();
        auto v2 = h1_twin->vertex();
        auto f_nei = h1_twin->face();
        auto h1_nei_next = h1_twin->next();
        auto h1_nei_prev = h1_nei_next;
        do {
            h1_nei_prev = h1_nei_prev->next();
        } while (h1_nei_prev->next() != h1_twin);

        // half edges
        h->next() = h1_nei_next;
        h1_nei_prev->next() = h1_prev;

        // vertices
        v1->halfedge() = h_twin;
        v2->halfedge() = h1_prev;

        // face
        f_nei->halfedge() = h1_nei_next;
        h->face() = f_nei;
        h1_prev->face() = f_nei;

        // delete
        deleteEdge(e1);
        deleteFace(f1);
        deleteHalfedge(h1_twin);
        deleteHalfedge(h1);
    }

    if (h2->next() == h2_prev) {
        // printf("Second\n");
        auto e2 = h2->edge();
        auto f2 = h2->face();
        auto v1 = h2->vertex();
        auto v2 = h2_twin->vertex();
        auto f_nei = h2_twin->face();
        auto h2_nei_next = h2_twin->next();
        auto h2_nei_prev = h2_nei_next;
        do {
            h2_nei_prev = h2_nei_prev->next();
        } while (h2_nei_prev->next() != h2_twin);

        // half edges
        h_twin->next() = h2_nei_next;
        h2_nei_prev->next() = h2_prev;

        // vertices
        v1->halfedge() = h;
        v2->halfedge() = h2_prev;

        // face
        f_nei->halfedge() = h2_nei_next;
        h_twin->face() = f_nei;
        h2_prev->face() = f_nei;

        // delete
        deleteEdge(e2);
        deleteFace(f2);
        deleteHalfedge(h2_twin);
        deleteHalfedge(h2);
    }

    printf("Get Centroid\n");
    Vector3D centroid = e->centroid();
    auto f1 = h->face();
    auto f2 = h_twin->face();

    // half edges
    auto currH = h->next();
    int n = 0;
    do {
        currH->vertex() = newVtx;
        currH = currH->twin()->next();
        printf("No. %d\n", ++n);
    } while (currH != h_twin);
    h1_prev->next() = h->next();
    h2_prev->next() = h_twin->next();
    cout << "past do while edge collapse" << endl;
    // vertex
    newVtx->halfedge() = h1_prev->twin();
    newVtx->position = centroid;

    // face
    f1->halfedge() = h1_prev;
    f2->halfedge() = h2_prev;

    printf("End of Edge Collapse: Cleanup\n");

    // delete
    //if (delVtx != newVtx) {
    //  deleteVertex(delVtx);
    //}
    deleteVertex(delVtx);
    deleteEdge(e);
    deleteHalfedge(h);
    deleteHalfedge(h_twin);

    printf("New vertex Position\n");
    cout << newVtx->position << endl;
    //newVtx->collapseSuccess = true;
    return newVtx;
}

VertexIter HalfedgeMesh::collapseFace(FaceIter f) {
  // TODO: (meshEdit)
  // This method should collapse the given face and return an iterator to
  // the new vertex created by the collapse.
  showError("collapseFace() not implemented.");
  return VertexIter();
}

FaceIter HalfedgeMesh::eraseVertex(VertexIter v) {
  // TODO: (meshEdit)
  // This method should replace the given vertex and all its neighboring
  // edges and faces with a single face, returning the new face.

  return FaceIter();
}

FaceIter HalfedgeMesh::eraseEdge(EdgeIter e) {
  // TODO: (meshEdit)
  // This method should erase the given edge and return an iterator to the
  // merged face.

  showError("eraseVertex() not implemented.");
  return FaceIter();
}

EdgeIter HalfedgeMesh::flipEdge(EdgeIter e0) {
    // TODO: (meshEdit)
    // This method should flip the given edge and return an iterator to the
    // flipped edge.
      // HALFEDGES
    HalfedgeIter h0 = e0->halfedge();
    HalfedgeIter h1 = h0->next();
    HalfedgeIter h2 = h1->next();
    HalfedgeIter h3 = h0->twin();
    HalfedgeIter h4 = h3->next();
    HalfedgeIter h5 = h4->next();
    HalfedgeIter h6 = h1->twin();
    HalfedgeIter h7 = h2->twin();
    HalfedgeIter h8 = h4->twin();
    HalfedgeIter h9 = h5->twin();

    // VERTICES
    VertexIter v0 = h0->vertex();
    VertexIter v1 = h3->vertex();
    VertexIter v2 = h8->vertex();
    VertexIter v3 = h6->vertex();
    // ...you fill in the rest!...

    // EDGES
    EdgeIter e1 = h5->edge();
    EdgeIter e2 = h4->edge();
    EdgeIter e3 = h2->edge();
    EdgeIter e4 = h1->edge();

    // ...you fill in the rest!...

    // FACES
    FaceIter f0 = h0->face();
    FaceIter f1 = h3->face();
    // ...you fill in the rest!...

    //VertexIter v4 = mesh.newVertex();
    // HALFEDGES
    h0->next() = h1;
    h0->twin() = h3;
    h0->vertex() = v2;
    h0->edge() = e0;
    h0->face() = f0;

    h1->next() = h2;
    h1->twin() = h7;
    h1->vertex() = v3;
    h1->edge() = e3;
    h1->face() = f0;

    h2->next() = h0;
    h2->twin() = h8;
    h2->vertex() = v0;
    h2->edge() = e2;
    h2->face() = f0;

    h3->next() = h4;
    h3->twin() = h0;
    h3->vertex() = v3;
    h3->edge() = e0;
    h3->face() = f1;

    h4->next() = h5;
    h4->twin() = h9;
    h4->vertex() = v2;
    h4->edge() = e1;
    h4->face() = f1;

    h5->next() = h3;
    h5->twin() = h6;
    h5->vertex() = v1;
    h5->edge() = e4;
    h5->face() = f1;

    h6->next() = h6->next();
    h6->twin() = h5;
    h6->vertex() = v3;
    h6->edge() = e4;
    h6->face() = h6->face();

    h7->next() = h7->next();
    h7->twin() = h1;
    h7->vertex() = v0;
    h7->edge() = e3;
    h7->face() = h7->face();

    h8->next() = h8->next();
    h8->twin() = h2;
    h8->vertex() = v2;
    h8->edge() = e2;
    h8->face() = h8->face();
    // ...you fill in the rest!...

    // ...and don't forget about the "outside" elements!...
    h9->next() = h9->next(); // didn't change, but set it anyway!
    h9->twin() = h4;
    h9->vertex() = v1;
    h9->edge() = e1;
    h9->face() = h9->face(); // didn't change, but set it anyway!

    // VERTICES
    v0->halfedge() = h2;
    v1->halfedge() = h5;
    v2->halfedge() = h4;
    v3->halfedge() = h3;

    // EDGES
    e0->halfedge() = h0; //...you fill in the rest!...
    e1->halfedge() = h4;
    e2->halfedge() = h2;
    e3->halfedge() = h1;
    e4->halfedge() = h6;
    // FACES
    f0->halfedge() = h0; //...you fill in the rest!...
    f1->halfedge() = h4;
    //  mesh.deleteVertex(v4);

  //  showError("flipEdge() not implemented.");
    return e0;//EdgeIter();
}

void HalfedgeMesh::subdivideQuad(bool useCatmullClark) {
  // Unlike the local mesh operations (like bevel or edge flip), we will perform
  // subdivision by splitting *all* faces into quads "simultaneously."  Rather
  // than operating directly on the halfedge data structure (which as you've
  // seen
  // is quite difficult to maintain!) we are going to do something a bit nicer:
  //
  //    1. Create a raw list of vertex positions and faces (rather than a full-
  //       blown halfedge mesh).
  //
  //    2. Build a new halfedge mesh from these lists, replacing the old one.
  //
  // Sometimes rebuilding a data structure from scratch is simpler (and even
  // more
  // efficient) than incrementally modifying the existing one.  These steps are
  // detailed below.

  // TODO Step I: Compute the vertex positions for the subdivided mesh.  Here
  // we're
  // going to do something a little bit strange: since we will have one vertex
  // in
  // the subdivided mesh for each vertex, edge, and face in the original mesh,
  // we
  // can nicely store the new vertex *positions* as attributes on vertices,
  // edges,
  // and faces of the original mesh.  These positions can then be conveniently
  // copied into the new, subdivided mesh.
  // [See subroutines for actual "TODO"s]
  if (useCatmullClark) {
    computeCatmullClarkPositions();
  } else {
    computeLinearSubdivisionPositions();
  }

  // TODO Step II: Assign a unique index (starting at 0) to each vertex, edge,
  // and
  // face in the original mesh.  These indices will be the indices of the
  // vertices
  // in the new (subdivided mesh).  They do not have to be assigned in any
  // particular
  // order, so long as no index is shared by more than one mesh element, and the
  // total number of indices is equal to V+E+F, i.e., the total number of
  // vertices
  // plus edges plus faces in the original mesh.  Basically we just need a
  // one-to-one
  // mapping between original mesh elements and subdivided mesh vertices.
  // [See subroutine for actual "TODO"s]
  assignSubdivisionIndices();

  // TODO Step III: Build a list of quads in the new (subdivided) mesh, as
  // tuples of
  // the element indices defined above.  In other words, each new quad should be
  // of
  // the form (i,j,k,l), where i,j,k and l are four of the indices stored on our
  // original mesh elements.  Note that it is essential to get the orientation
  // right
  // here: (i,j,k,l) is not the same as (l,k,j,i).  Indices of new faces should
  // circulate in the same direction as old faces (think about the right-hand
  // rule).
  // [See subroutines for actual "TODO"s]
  vector<vector<Index> > subDFaces;
  vector<Vector3D> subDVertices;
  buildSubdivisionFaceList(subDFaces);
  buildSubdivisionVertexList(subDVertices);

  // TODO Step IV: Pass the list of vertices and quads to a routine that clears
  // the
  // internal data for this halfedge mesh, and builds new halfedge data from
  // scratch,
  // using the two lists.
  rebuild(subDFaces, subDVertices);
}

/**
 * Compute new vertex positions for a mesh that splits each polygon
 * into quads (by inserting a vertex at the face midpoint and each
 * of the edge midpoints).  The new vertex positions will be stored
 * in the members Vertex::newPosition, Edge::newPosition, and
 * Face::newPosition.  The values of the positions are based on
 * simple linear interpolation, e.g., the edge midpoints and face
 * centroids.
 */
void HalfedgeMesh::computeLinearSubdivisionPositions() {
  // TODO For each vertex, assign Vertex::newPosition to
  // its original position, Vertex::position.

  // TODO For each edge, assign the midpoint of the two original
  // positions to Edge::newPosition.

  // TODO For each face, assign the centroid (i.e., arithmetic mean)
  // of the original vertex positions to Face::newPosition.  Note
  // that in general, NOT all faces will be triangles!
  showError("computeLinearSubdivisionPositions() not implemented.");
}

/**
 * Compute new vertex positions for a mesh that splits each polygon
 * into quads (by inserting a vertex at the face midpoint and each
 * of the edge midpoints).  The new vertex positions will be stored
 * in the members Vertex::newPosition, Edge::newPosition, and
 * Face::newPosition.  The values of the positions are based on
 * the Catmull-Clark rules for subdivision.
 */
void HalfedgeMesh::computeCatmullClarkPositions() {
  // TODO The implementation for this routine should be
  // a lot like HalfedgeMesh::computeLinearSubdivisionPositions(),
  // except that the calculation of the positions themsevles is
  // slightly more involved, using the Catmull-Clark subdivision
  // rules. (These rules are outlined in the Developer Manual.)

  // TODO face

  // TODO edges

  // TODO vertices
  showError("computeCatmullClarkPositions() not implemented.");
}

/**
 * Assign a unique integer index to each vertex, edge, and face in
 * the mesh, starting at 0 and incrementing by 1 for each element.
 * These indices will be used as the vertex indices for a mesh
 * subdivided using Catmull-Clark (or linear) subdivision.
 */
void HalfedgeMesh::assignSubdivisionIndices() {
  // TODO Start a counter at zero; if you like, you can use the
  // "Index" type (defined in halfedgeMesh.h)

  // TODO Iterate over vertices, assigning values to Vertex::index

  // TODO Iterate over edges, assigning values to Edge::index

  // TODO Iterate over faces, assigning values to Face::index
  showError("assignSubdivisionIndices() not implemented.");
}

/**
 * Build a flat list containing all the vertex positions for a
 * Catmull-Clark (or linear) subdivison of this mesh.  The order of
 * vertex positions in this list must be identical to the order
 * of indices assigned to Vertex::newPosition, Edge::newPosition,
 * and Face::newPosition.
 */
void HalfedgeMesh::buildSubdivisionVertexList(vector<Vector3D>& subDVertices) {
  // TODO Resize the vertex list so that it can hold all the vertices.

  // TODO Iterate over vertices, assigning Vertex::newPosition to the
  // appropriate location in the new vertex list.

  // TODO Iterate over edges, assigning Edge::newPosition to the appropriate
  // location in the new vertex list.

  // TODO Iterate over faces, assigning Face::newPosition to the appropriate
  // location in the new vertex list.
  showError("buildSubdivisionVertexList() not implemented.");
}

/**
 * Build a flat list containing all the quads in a Catmull-Clark
 * (or linear) subdivision of this mesh.  Each quad is specified
 * by a vector of four indices (i,j,k,l), which come from the
 * members Vertex::index, Edge::index, and Face::index.  Note that
 * the ordering of these indices is important because it determines
 * the orientation of the new quads; it is also important to avoid
 * "bowties."  For instance, (l,k,j,i) has the opposite orientation
 * of (i,j,k,l), and if (i,j,k,l) is a proper quad, then (i,k,j,l)
 * will look like a bowtie.
 */
void HalfedgeMesh::buildSubdivisionFaceList(vector<vector<Index> >& subDFaces) {
  // TODO This routine is perhaps the most tricky step in the construction of
  // a subdivision mesh (second, perhaps, to computing the actual Catmull-Clark
  // vertex positions).  Basically what you want to do is iterate over faces,
  // then for each for each face, append N quads to the list (where N is the
  // degree of the face).  For this routine, it may be more convenient to simply
  // append quads to the end of the list (rather than allocating it ahead of
  // time), though YMMV.  You can of course iterate around a face by starting
  // with its first halfedge and following the "next" pointer until you get
  // back to the beginning.  The tricky part is making sure you grab the right
  // indices in the right order---remember that there are indices on vertices,
  // edges, AND faces of the original mesh.  All of these should get used.  Also
  // remember that you must have FOUR indices per face, since you are making a
  // QUAD mesh!

  // TODO iterate over faces
  // TODO loop around face
  // TODO build lists of four indices for each sub-quad
  // TODO append each list of four indices to face list
  showError("buildSubdivisionFaceList() not implemented.");
}

FaceIter HalfedgeMesh::bevelVertex(VertexIter v) {
  // TODO This method should replace the vertex v with a face, corresponding to
  // a bevel operation. It should return the new face.  NOTE: This method is
  // responsible for updating the *connectivity* of the mesh only---it does not
  // need to update the vertex positions.  These positions will be updated in
  // HalfedgeMesh::bevelVertexComputeNewPositions (which you also have to
  // implement!)

  showError("bevelVertex() not implemented.");
  return facesBegin();
}

FaceIter HalfedgeMesh::bevelEdge(EdgeIter e) {
  // TODO This method should replace the edge e with a face, corresponding to a
  // bevel operation. It should return the new face.  NOTE: This method is
  // responsible for updating the *connectivity* of the mesh only---it does not
  // need to update the vertex positions.  These positions will be updated in
  // HalfedgeMesh::bevelEdgeComputeNewPositions (which you also have to
  // implement!)

  showError("bevelEdge() not implemented.");
  return facesBegin();
}

FaceIter HalfedgeMesh::bevelFace(FaceIter f) {
    // TODO This method should replace the face f with an additional, inset face
    // (and ring of faces around it), corresponding to a bevel operation. It
    // should return the new face.  NOTE: This method is responsible for updating
    // the *connectivity* of the mesh only---it does not need to update the vertex
    // positions.  These positions will be updated in
    // HalfedgeMesh::bevelFaceComputeNewPositions (which you also have to
    // implement!)
    if (f->isBoundary()) { return f; }
    int sides = f->degree();
    vector<HalfedgeIter> new_h;
    vector<VertexIter> new_v;
    vector<EdgeIter> new_e;
    vector<FaceIter> new_face;
    HalfedgeIter old_h = f->halfedge();

    for (int i = 0; i < sides; ++i) {
        new_face.push_back(newFace());
        new_v.push_back(newVertex());
        new_e.push_back(newEdge());
        new_e.push_back(newEdge());
        new_h.push_back(newHalfedge());
        new_h.push_back(newHalfedge());
        new_h.push_back(newHalfedge());
        new_h.push_back(newHalfedge());
    //    old_h = old_h->next();
    }
    //FaceIter resultFace = f;
    for (int i = 0; i < sides; ++i) {
        old_h->face() = new_face[i];
        auto temp = old_h->next();
        old_h->next() = new_h[4 * i];

        new_h[4 * i]->vertex() = temp->vertex();
        new_h[4 * i]->next() = new_h[4 * i + 1];
        new_h[4 * i]->edge() = new_e[2 * i];
        new_h[4 * i]->twin() = new_h[(i + 1 == sides) ? 2 : 4 * (i + 1) + 2];//exceed!
        new_h[4 * i]->face() = new_face[i];

        new_h[4 * i + 1]->vertex() = new_v[i];
        new_h[4 * i + 1]->next() = new_h[4 * i + 2];
        new_h[4 * i + 1]->edge() = new_e[2 * i + 1];
        new_h[4 * i + 1]->twin() = new_h[4 * i + 3];
        new_h[4 * i + 1]->face() = new_face[i];

        new_h[4 * i + 2]->vertex() = new_v[(i - 1 < 0) ? sides - 1 : i - 1];
        new_h[4 * i + 2]->next() = old_h;
        new_h[4 * i + 2]->edge() = new_e[(i - 1 < 0) ? 2 * (sides - 1) : 2 * (i - 1)];
        new_h[4 * i + 2]->twin() = new_h[(i - 1 < 0) ? 4 * (sides - 1) : 4 * (i - 1)];
        new_h[4 * i + 2]->face() = new_face[i];

        new_h[4 * i + 3]->vertex() = new_v[(i - 1 < 0) ? sides - 1 : i - 1];
        new_h[4 * i + 3]->next() = new_h[(i + 1 == sides) ? 3 : 4 * (i + 1) + 3];
        new_h[4 * i + 3]->edge() = new_e[2 * i + 1];
        new_h[4 * i + 3]->twin() = new_h[4 * i + 1];
        new_h[4 * i + 3]->face() = f;

        new_e[2 * i]->halfedge() = new_h[4 * i];
        new_e[2 * i + 1]->halfedge() = new_h[4 * i + 1];
        new_v[i]->halfedge() = new_h[4 * i + 1];
        new_v[i]->position = temp->vertex()->position;
        new_face[i]->halfedge() = old_h;

        old_h = temp;
        
    }
    f->halfedge() = new_h[3];
    //showError("bevelFace() not implemented.");
    return f;
}


void HalfedgeMesh::bevelFaceComputeNewPositions(
    vector<Vector3D>& originalVertexPositions,
    vector<HalfedgeIter>& newHalfedges, double normalShift,
    double tangentialInset) {
  // TODO Compute new vertex positions for the vertices of the beveled face.
  //
  // These vertices can be accessed via newHalfedges[i]->vertex()->position for
  // i = 1, ..., newHalfedges.size()-1.
  //
  // The basic strategy here is to loop over the list of outgoing halfedges,
  // and use the preceding and next vertex position from the original mesh
  // (in the originalVertexPositions array) to compute an offset vertex
  // position.
  //
  // Note that there is a 1-to-1 correspondence between halfedges in
  // newHalfedges and vertex positions
  // in orig.  So, you can write loops of the form
  //
  // for( int i = 0; i < newHalfedges.size(); hs++ )
  // {
  //    Vector3D pi = originalVertexPositions[i]; // get the original vertex
  //    position correponding to vertex i
  // }
  //
    FaceIter f = newHalfedges[0]->twin()->next()->twin()->face();

    Vector3D f_norm = f->normal();
    Vector3D f_center = f->centroid();

    size_t n = originalVertexPositions.size();

    for (size_t i = 0; i < n; i++) {
        Vector3D pi = originalVertexPositions[i];
        newHalfedges[i]->vertex()->position = newHalfedges[i]->vertex()->position + f_norm * normalShift + (f_center - pi) * tangentialInset;
    }
}

void HalfedgeMesh::bevelVertexComputeNewPositions(
    Vector3D originalVertexPosition, vector<HalfedgeIter>& newHalfedges,
    double tangentialInset) {
  // TODO Compute new vertex positions for the vertices of the beveled vertex.
  //
  // These vertices can be accessed via newHalfedges[i]->vertex()->position for
  // i = 1, ..., hs.size()-1.
  //
  // The basic strategy here is to loop over the list of outgoing halfedges,
  // and use the preceding and next vertex position from the original mesh
  // (in the orig array) to compute an offset vertex position.

}

void HalfedgeMesh::bevelEdgeComputeNewPositions(
    vector<Vector3D>& originalVertexPositions,
    vector<HalfedgeIter>& newHalfedges, double tangentialInset) {
  // TODO Compute new vertex positions for the vertices of the beveled edge.
  //
  // These vertices can be accessed via newHalfedges[i]->vertex()->position for
  // i = 1, ..., newHalfedges.size()-1.
  //
  // The basic strategy here is to loop over the list of outgoing halfedges,
  // and use the preceding and next vertex position from the original mesh
  // (in the orig array) to compute an offset vertex position.
  //
  // Note that there is a 1-to-1 correspondence between halfedges in
  // newHalfedges and vertex positions
  // in orig.  So, you can write loops of the form
  //
  // for( int i = 0; i < newHalfedges.size(); i++ )
  // {
  //    Vector3D pi = originalVertexPositions[i]; // get the original vertex
  //    position correponding to vertex i
  // }
  //

}

void HalfedgeMesh::splitPolygons(vector<FaceIter>& fcs) {
  for (auto f : fcs) splitPolygon(f);
}

void HalfedgeMesh::splitPolygon(FaceIter f) {
    // TODO: (meshedit) 
    // Triangulate a polygonal face
    if (f->degree() == 3)return;

    HalfedgeIter h0 = f->halfedge();
    VertexIter v0 = h0->vertex();
    HalfedgeIter h1 = h0->next();
    VertexIter v1 = h1->vertex();
    HalfedgeIter h2 = h1->next();
    VertexIter v2 = h2->vertex();
    HalfedgeIter h3 = h2->next();
    VertexIter v3 = h3->vertex();

    HalfedgeIter newh1 = newHalfedge();
    HalfedgeIter newh2 = newHalfedge();
    EdgeIter newe = newEdge();
    FaceIter newf = newFace();
    newe->halfedge() = newh1;

    newh1->vertex() = v3;
    newh1->next() = h1;
    newh1->edge() = newe;
    newh1->twin() = newh2;
    newh1->face() =newf;

    newh2->vertex() = v1;
    newh2->next() = h3;
    newh2->edge() = newe;
    newh2->twin() = newh1;
    newh2->face() = f;

    h0->next() = newh2;

    h2->next() = newh1;

    h2->face() = newf;
    h1->face() = newf;

    f->halfedge() = newh2;
    newf->halfedge() = newh1;

    splitPolygon(f);
   // showError("splitPolygon() not implemented.");
}

EdgeRecord::EdgeRecord(EdgeIter& _edge) : edge(_edge) {
  // TODO: (meshEdit)
  // Compute the combined quadric from the edge endpoints.
  // -> Build the 3x3 linear system whose solution minimizes the quadric error
  //    associated with these two endpoints.
  // -> Use this system to solve for the optimal position, and store it in
  //    EdgeRecord::optimalPoint.
  // -> Also store the cost associated with collapsing this edg in
  //    EdgeRecord::Cost.
}

void MeshResampler::upsample(HalfedgeMesh& mesh)
// This routine should increase the number of triangles in the mesh using Loop
// subdivision.
{
  // TODO: (meshEdit)
  // Compute new positions for all the vertices in the input mesh, using
  // the Loop subdivision rule, and store them in Vertex::newPosition.
  // -> At this point, we also want to mark each vertex as being a vertex of the
  //    original mesh.
  // -> Next, compute the updated vertex positions associated with edges, and
  //    store it in Edge::newPosition.
  // -> Next, we're going to split every edge in the mesh, in any order.  For
  //    future reference, we're also going to store some information about which
  //    subdivided edges come from splitting an edge in the original mesh, and
  //    which edges are new, by setting the flat Edge::isNew. Note that in this
  //    loop, we only want to iterate over edges of the original mesh.
  //    Otherwise, we'll end up splitting edges that we just split (and the
  //    loop will never end!)
  // -> Now flip any new edge that connects an old and new vertex.
  // -> Finally, copy the new vertex positions into final Vertex::position.

  // Each vertex and edge of the original surface can be associated with a
  // vertex in the new (subdivided) surface.
  // Therefore, our strategy for computing the subdivided vertex locations is to
  // *first* compute the new positions
  // using the connectity of the original (coarse) mesh; navigating this mesh
  // will be much easier than navigating
  // the new subdivided (fine) mesh, which has more elements to traverse.  We
  // will then assign vertex positions in
  // the new mesh based on the values we computed for the original mesh.

  // Compute updated positions for all the vertices in the original mesh, using
  // the Loop subdivision rule.

  // Next, compute the updated vertex positions associated with edges.

  // Next, we're going to split every edge in the mesh, in any order.  For
  // future
  // reference, we're also going to store some information about which
  // subdivided
  // edges come from splitting an edge in the original mesh, and which edges are
  // new.
  // In this loop, we only want to iterate over edges of the original
  // mesh---otherwise,
  // we'll end up splitting edges that we just split (and the loop will never
  // end!)

  // Finally, flip any new edge that connects an old and new vertex.

  // Copy the updated vertex positions to the subdivided mesh.
  showError("upsample() not implemented.");
}

void MeshResampler::downsample(HalfedgeMesh& mesh) {
  // TODO: (meshEdit)
  // Compute initial quadrics for each face by simply writing the plane equation
  // for the face in homogeneous coordinates. These quadrics should be stored
  // in Face::quadric
  // -> Compute an initial quadric for each vertex as the sum of the quadrics
  //    associated with the incident faces, storing it in Vertex::quadric
  // -> Build a priority queue of edges according to their quadric error cost,
  //    i.e., by building an EdgeRecord for each edge and sticking it in the
  //    queue.
  // -> Until we reach the target edge budget, collapse the best edge. Remember
  //    to remove from the queue any edge that touches the collapsing edge
  //    BEFORE it gets collapsed, and add back into the queue any edge touching
  //    the collapsed vertex AFTER it's been collapsed. Also remember to assign
  //    a quadric to the collapsed vertex, and to pop the collapsed edge off the
  //    top of the queue.
  showError("downsample() not implemented.");
}

void MeshResampler::resample(HalfedgeMesh& mesh) {
  // TODO: (meshEdit)
  // Compute the mean edge length.
  // Repeat the four main steps for 5 or 6 iterations
  // -> Split edges much longer than the target length (being careful about
  //    how the loop is written!)
  // -> Collapse edges much shorter than the target length.  Here we need to
  //    be EXTRA careful about advancing the loop, because many edges may have
  //    been destroyed by a collapse (which ones?)
  // -> Now flip each edge if it improves vertex degree
  // -> Finally, apply some tangential smoothing to the vertex positions
  showError("resample() not implemented.");
}

}  // namespace CMU462
