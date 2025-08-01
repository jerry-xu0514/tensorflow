/* Copyright 2024 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef XLA_PYTHON_IFRT_PROXY_COMMON_VERSIONS_H_
#define XLA_PYTHON_IFRT_PROXY_COMMON_VERSIONS_H_

namespace xla {
namespace ifrt {
namespace proxy {

namespace protocol_version {

enum {
  // Versions kAncient are named and are only referred to by their numbers. See
  // VERSIONS.md to see the explanation of the numbers.
  kAncient = 10,

  // kClientHandlesOptimization2 introduces a set of performance optimizations
  // where the client generates array handles.
  kClientHandlesOptimization2 = 11,

  // kClientHandlesExecutableOptimization introduces a set of performance
  // optimizations where the client generates array handles for operations
  // related to LoadedExecutable.
  kClientHandlesExecutableOptimization = 12,

  // kAssembleArrayFromSingleDeviceArraysWithDType adds a DType argument to
  // AssembleArrayFromSingleDeviceArrays to support non-addressable arrays.
  kAssembleArrayFromSingleDeviceArraysWithDType = 13,

  // kMakeArraysFromHostBufferShards adds Client::MakeArraysFromHostBufferShards
  // support.
  kMakeArraysFromHostBufferShards = 14,

  // kSerDesVersioning users IFRT SerDes versioning for IFRT types.
  kSerDesVersioning = 15,

  // kSentiel is used to derive kCurrent below. Keep this as the last value of
  // the enum.
  kSentiel,
};

// The minimum protocol_version that the current client code understands.
inline constexpr int kClientMin = kSerDesVersioning;

// The minimum protocol_version that the current server code understands.
inline constexpr int kServerMin = 3;

// The maximum protocol_version that the current client and server code
// understand.
constexpr int kCurrent = kSentiel - 1;

}  // namespace protocol_version

}  // namespace proxy
}  // namespace ifrt
}  // namespace xla

#endif  // XLA_PYTHON_IFRT_PROXY_COMMON_VERSIONS_H_
