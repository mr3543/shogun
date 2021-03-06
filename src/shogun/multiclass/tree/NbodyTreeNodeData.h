/*
 * Copyright (c) The Shogun Machine Learning Toolbox
 * Written (w) 2014 Parijat Mazumdar
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the Shogun Development Team.
 */


#ifndef _NBODYTREENODEDATA_H__
#define _NBODYTREENODEDATA_H__

#include <shogun/lib/config.h>

namespace shogun
{
/** @brief structure to store data of a node of
 * N-Body tree. This can be used as a template type in
 * TreeMachineNode class. N-Body tree building algorithm uses nodes
 * of type BinaryTreeMachineNode<NbodyTreeNodeData>
 */
struct NbodyTreeNodeData
{
	/** start index */
	index_t start_idx;

	/** end index */
	index_t end_idx;

	/** is leaf */
	bool is_leaf;

	/** bounding box upper bounds (in ball tree used only for fast calculation of max spread dimension) */
	SGVector<float64_t> bbox_upper;

	/** bounding box lower bounds (in ball tree used only for fast calculation of max spread dimension) */
	SGVector<float64_t> bbox_lower;

	/** radius of point cloud in node */
	float64_t radius;

	/** node center - used only in ball tree */
	SGVector<float64_t> center;

	/** constructor */
	NbodyTreeNodeData()
	{
		start_idx=0;
		end_idx=0;
		is_leaf=false;
		bbox_upper=SGVector<float64_t>();
		bbox_lower=SGVector<float64_t>();
		center=SGVector<float64_t>();
		radius=0;
	}
};

template<class T>
constexpr void register_params(NbodyTreeNodeData& n, T* o)
{
	o->watch_param("start_idx", &n.start_idx, AnyParameterProperties("start index"));
	o->watch_param("end_idx", &n.end_idx, AnyParameterProperties("end index"));
	o->watch_param("is_leaf", &n.is_leaf, AnyParameterProperties("is leaf"));
	o->watch_param("bbox_upper", &n.bbox_upper, AnyParameterProperties("bounding box upper bounds"));
	o->watch_param("bbox_lower", &n.bbox_lower, AnyParameterProperties("bounding box lower bounds"));
	o->watch_param("radius", &n.radius, AnyParameterProperties("radius of point cloud in node"));
	o->watch_param("center", &n.center, AnyParameterProperties("node center"));
}

} /* shogun */

#endif /* _NBODYTREENODEDATA_H__ */
