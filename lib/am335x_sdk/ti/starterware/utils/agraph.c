#include "types.h"
#include "agraph.h"
#include <string.h>
#include <assert.h>

/*----------------------------------------------------------------------------*/ 
#define ag_get_node_fast(ag, id)  \
    (&((ag)->nodes[id]))

/*----------------------------------------------------------------------------*/ 
#if 0
static int ag_clear_visited(agraph *ag) {
    int nbytes = BITNSLOTS(ag->nodes_max);
    memset(ag->visited, 0, nbytes);
    return 0;
}
#endif

/*----------------------------------------------------------------------------*/ 
bool 
ag_valid_node(agraph_ptr ag, ag_node_id id) {
    return !(ag == NULL || id >= ag->nodes_max);
}

/*----------------------------------------------------------------------------*/ 
ag_node_cptr 
ag_get_node(agraph_ptr ag, ag_node_id id) {
    if(!ag_valid_node(ag, id)) { return NULL; }
    return ag_get_node_fast(ag, id);
}

/*----------------------------------------------------------------------------*/ 
ag_prop_cptr 
ag_get_node_prop(ag_node_cptr np) {
  if(!np) { return NULL; }
  return np->prop;
}

/*----------------------------------------------------------------------------*/ 
bool
ag_get_predecessors(agraph_ptr ag, ag_node_id id, ag_node_id_cvec *pred, ag_size_t *npred) {
    assert(pred != NULL && npred != NULL);
    if(!ag_valid_node(ag, id)) { return FALSE; }
    ag_node_cptr node = ag_get_node_fast(ag, id);
    *pred = node->edge_in;
    *npred = node->edge_in_max;
    return TRUE;
}

/*----------------------------------------------------------------------------*/ 
ag_prop_cptr 
ag_get_edge_prop(ag_edge_cptr ep) {
  if(!ep) { return NULL; }
  return ep->prop;
}

/*----------------------------------------------------------------------------*/ 


ag_prop_type ag_get_prop_type(const ag_node* ag, ag_node_id id)
{    return ag[id].prop->ptype;}
const void* ag_get_prop_ptr(const ag_node* ag, ag_node_id id)
{    return ag[id].prop->pvalue;}