/**
 *  \file       agraph.h
 *  \brief      Acyclic Graph Abstract Data Type
 *  \author     R. Swaminathan (swaminathan@ti.com)
 *  \date       09/17/2013
 */
 
/*
 * Copyright (C) 2013 - 2018 Texas Instruments Incorporated - http://www.ti.com/
 */
/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
#ifndef INC_AGRAPH_H
#define INC_AGRAPH_H

/*------------------------------------------------------------------------------ */
/*  Header Files                                                                 */
/*------------------------------------------------------------------------------ */
#include <limits.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*------------------------------------------------------------------------------ */
/*  Macros                                                                       */ 
/*------------------------------------------------------------------------------ */
#define BITMASK(b)      (1<< ((b) % CHAR_BIT)
#define BITSLOT(b)      ((b) / CHAR_BIT)
#define BITSET(a,b)     ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a,b)   ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a,b)    ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb)   (((nb) + CHAR_BIT - 1) / CHAR_BIT)

/*------------------------------------------------------------------------------ */
/*  Typedefs                                                                     */
/*------------------------------------------------------------------------------ */
typedef uint8_t           ag_node_id;
typedef ag_node_id       *ag_node_id_vec;
typedef const ag_node_id *ag_node_id_cvec;
typedef uint8_t           ag_prop_type;
typedef uint8_t           ag_size_t;

/*------------------------------------------------------------------------------ */
/*  Struct Declarations                                                          */
/*------------------------------------------------------------------------------ */
/**
 * \brief   Graph container to hold arbitary data-type
 */
typedef struct {
    /* Property type used to interpret pvalue*/
    ag_prop_type ptype;
    /* Property value*/
     const void *pvalue;
} ag_prop, *ag_prop_ptr;
typedef const ag_prop *ag_prop_cptr;   

/**
 * \brief   Edge stuct that encapsulates a property
 */
typedef struct {
    /* Target node-id*/
    ag_node_id  to;
    /* Edge property specific to this edge*/
    ag_prop_cptr prop;
} ag_edge, *ag_edge_ptr;
typedef const ag_edge *ag_edge_cptr;
typedef const ag_edge *ag_edge_cvec;

/**
 *  \brief   List of edges originating from a node
 */
typedef struct {
    /* Source of edge*/
    ag_node_id  from;
    /* Target(s) of edge*/
    ag_edge_cvec to_nodes;
    /* Number of elements in to_nodes vector*/
    ag_size_t   to_nodes_max;
} ag_edges, *ag_edges_ptr;
typedef const ag_edges *ag_edges_cvec;

/**
 *  \brief  Graph node optimized for PM
 */
typedef struct {
    /* Node Property*/
    ag_prop_cptr  prop;
    /* List of edges incident on this node (Parent node-ids)*/
    ag_node_id_cvec edge_in;
    /* Number of edges incident on this node*/
    ag_size_t edge_in_max;
} ag_node, *ag_node_ptr;
typedef const ag_node *ag_node_cptr;
typedef const ag_node *ag_node_cvec;

/**
 *  \brief  Graph data structure
 */
typedef struct {
    ag_size_t       nodes_max;
    ag_node_cvec    nodes;
    ag_size_t       edges_max;
    ag_edges_cvec   edges;
    /* Bitvector to identify list of visited nodes for traversal*/
    uint8_t         *visited;
} agraph, *agraph_ptr;

/*------------------------------------------------------------------------------ */
/* Graph ADT APIs                                                                */
/*-------------------------------------------------------------------------------*/
typedef ag_node_id (*select_node)(ag_node_id_cvec);
typedef void (*visitor_cb)(agraph_ptr ag, ag_node_id id, void *ctx);

/**
 * \brief     Is the given node-id valid?
 * \param[in] ag: agraph_ptr
 * \param[in] id: ag_node_id
 * \return    bool: true on valid, false otherwise
 */
bool ag_valid_node(agraph_ptr ag, ag_node_id id);

/**
 * \brief     Get the node_ptr corresponding to the node_id
 * \param[in] ag: agraph_ptr
 * \param[in] id: ag_node_id
 * \return    ag_node_cptr: NULL if node is not found
 */
ag_node_cptr ag_get_node(agraph_ptr ag, ag_node_id id); 

/**
 * \brief     Get the property corresponding to the node_id
 * \param[in] ag: agraph_ptr
 * \param[in] np: ag_node_cptr
 * \return    ag_prop_cptr: NULL if np is NULL, or prop not defined
 */
ag_prop_cptr ag_get_node_prop(ag_node_cptr np); 

/**
 * \brief     Get the the list of predecessor nodes
 * \param[in] ag: agraph_ptr
 * \param[in] id: node_id
 * \param[out] pred: ag_node_id_cvec*: 
 * \param[out] npred: ag_size_t
 * \return    Success
 */
bool ag_get_predecessors(agraph_ptr ag, ag_node_id id, ag_node_id_cvec *pred, ag_size_t *npred);

/**
 * \brief     Get the edge_ptr connecting from-to node_ids.
 * \param[in] ag: agraph_ptr
 * \param[in] from: node_id
 * \param[in] to: node_id
 * \return    ag_edge_cptr: NULL if edge is not found/no-edge property has been
 *            defined for that edge
 */
ag_edge_cptr ag_get_edge(agraph_ptr ag, ag_node_id from, ag_node_id to);

/**
 * \brief     Get the property corresponding to the edge
 * \param[in] ag: agraph_ptr
 * \param[in] ep: ag_edge_cptr
 * \return    ag_prop_cptr: NULL if ep is NULL, or prop not defined
 */
ag_prop_cptr ag_get_edge_prop(ag_edge_cptr ep);

ag_prop_type ag_get_prop_type(const ag_node* ag, ag_node_id id);
const void* ag_get_prop_ptr(const ag_node* ag, ag_node_id id);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INC_AGRAPH_H */

