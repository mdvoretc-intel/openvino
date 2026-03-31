// Copyright (C) 2018-2026 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_base_opencl.h"
#include "count_nonzero_params.h"

namespace kernel_selector {
class CountNonzeroKernelGroup : public KernelBaseOpenCL {
public:
    CountNonzeroKernelGroup() : KernelBaseOpenCL("count_nonzero_group") {}
    virtual ~CountNonzeroKernelGroup() {}

    struct DispatchData : public CommonDispatchData {
        size_t dataSize;
        DispatchData() : dataSize(1) {}
    };

    virtual DispatchData SetDefault(const count_nonzero_params& params) const;
    KernelsData GetKernelsData(const Params& params) const override;
    KernelsPriority GetKernelsPriority(const Params& params) const override;
    ParamsKey GetSupportedKey() const override;
    DeviceFeaturesKey get_required_device_features_key(const Params& params) const override;

protected:
    bool Validate(const Params& pp) const override;
    void GetUpdateDispatchDataFunc(KernelData& kd) const override;
};
}  // namespace kernel_selector
