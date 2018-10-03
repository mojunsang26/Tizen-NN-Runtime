/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __NEURUN_KERNEL_CPU_CONVOLUTIONLAYER_H__
#define __NEURUN_KERNEL_CPU_CONVOLUTIONLAYER_H__

#include <NeuralNetworks.h>

#include <arm_compute/runtime/IFunction.h>

#include "kernel/cpu/OperationUtils.h"

namespace neurun
{
namespace kernel
{
namespace cpu
{

class ConvolutionLayer : public ::arm_compute::IFunction
{
public:
  ConvolutionLayer();

public:
  bool convFloat32();

  bool convQuant8();

  void configure(uint8_t *inputData, const Shape inputShape, uint8_t *kernelData,
                 const Shape kernelShape, uint8_t *biasData, const Shape biasShape,
                 const uint32_t paddingLeft, const uint32_t paddingRight, const uint32_t paddingTop,
                 const uint32_t paddingBottom, const uint32_t strideW, const uint32_t strideH,
                 const FuseCode activation, uint8_t *outputData, const Shape outputShape);

  void run();

private:
  uint8_t *_inputData;
  uint8_t *_kernelData;
  uint8_t *_outputData;
  uint8_t *_biasData;

  Shape _inputShape;
  Shape _kernelShape;
  Shape _outputShape;
  Shape _biasShape;

  uint32_t _paddingLeft;
  uint32_t _paddingTop;
  uint32_t _paddingRight;
  uint32_t _paddingBottom;

  uint32_t _strideWidth;
  uint32_t _strideHeight;

  FuseCode _activation;

  OperandType _inputType;
};

} // namespace cpu
} // namespace kernel
} // namespace neurun

#endif // __NEURUN_KERNEL_CPU_CONVOLUTIONLAYER_H__