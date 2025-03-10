/**
 * \file dnn/src/naive/batched_matrix_mul/opr_impl.h
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2021 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 */
#pragma once
#include "megdnn/oprs.h"

namespace megdnn {
namespace naive {

class BatchedMatrixMulForwardImpl : public BatchedMatrixMulForward {
public:
    BatchedMatrixMulForwardImpl(Handle* handle);
    void exec(_megdnn_tensor_in A, _megdnn_tensor_in B, _megdnn_tensor_out C,
              _megdnn_workspace workspace) override;

    size_t get_workspace_in_bytes(const TensorLayout& A, const TensorLayout& B,
                                  const TensorLayout& C) override;

    std::vector<Algorithm*> get_all_algorithms(
            const TensorLayout& /*A*/, const TensorLayout& /*B*/,
            const TensorLayout& /*C*/) override;

    Algorithm* get_algorithm_heuristic(const TensorLayout& /*A*/,
                                       const TensorLayout& /*B*/,
                                       const TensorLayout& /*C*/,
                                       size_t /*workspace_limit_in_bytes*/,
                                       bool /* reproducible */) override;

    Algorithm* get_algorithm_from_desc(const AlgorithmDesc&) override;

    const char* get_algorithm_set_name() const override { return "DEFAULT"; }

private:
    std::unique_ptr<MatrixMulForward> m_opr;
};

}  // namespace naive
}  // namespace megdnn

// vim: syntax=cpp.doxygen
