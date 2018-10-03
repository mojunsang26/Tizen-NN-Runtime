/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "internal/op/Squeeze.h"
#include "internal/op/NodeVisitor.h"

#include <cassert>

namespace internal
{
namespace tflite
{
namespace op
{
namespace Squeeze
{

void Node::accept(NodeVisitor &&v) const { v.visit(*this); }

} // namespace Squeeze
} // namespace op
} // namespace tflite
} // namespace internal

namespace internal
{
namespace tflite
{
namespace op
{
namespace Squeeze
{
// dims_index is optional input
// if dims_index is not provided, dims_index is set to -1
Param::Param(uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount,
             const uint32_t *outputs)
{
  assert(inputCount == 1 || inputCount == 2);
  assert(outputCount == 1);

  output_index = outputs[0];

  input_index = inputs[0];

  // dims_index_optional = -1 by default
  if (inputCount == 2)
    dims_index_optional = inputs[1];
}

} // namespace Squeeze
} // namespace op
} // namespace tflite
} // namespace internal