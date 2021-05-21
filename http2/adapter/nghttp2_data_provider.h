#ifndef QUICHE_HTTP2_ADAPTER_NGHTTP2_DATA_PROVIDER_H_
#define QUICHE_HTTP2_ADAPTER_NGHTTP2_DATA_PROVIDER_H_

#include "http2/adapter/data_source.h"
#include "third_party/nghttp2/src/lib/includes/nghttp2/nghttp2.h"

namespace http2 {
namespace adapter {

// Assumes |source| is a DataFrameSource.
ssize_t DataFrameSourceReadCallback(nghttp2_session* /*session */,
                                    int32_t /* stream_id */,
                                    uint8_t* /* buf */,
                                    size_t length,
                                    uint32_t* data_flags,
                                    nghttp2_data_source* source,
                                    void* /* user_data */);

int DataFrameSourceSendCallback(nghttp2_session* /* session */,
                                nghttp2_frame* /* frame */,
                                const uint8_t* framehd,
                                size_t length,
                                nghttp2_data_source* source,
                                void* /* user_data */);

// Does not take ownership of |source|.
nghttp2_data_provider MakeDataProvider(DataFrameSource* source);

}  // namespace adapter
}  // namespace http2

#endif  // QUICHE_HTTP2_ADAPTER_NGHTTP2_DATA_PROVIDER_H_