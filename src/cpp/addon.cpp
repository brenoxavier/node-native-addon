#include <napi.h>
#include "graph.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Graph::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)
