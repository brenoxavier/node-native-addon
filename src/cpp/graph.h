#ifndef ADDON_GRAPH_H
#define ADDON_GRAPH_H

#include <napi.h>

class Graph : public Napi::ObjectWrap<Graph> {
    public:
        explicit Graph(const Napi::CallbackInfo& info);
        static Napi::Object Init(Napi::Env env, Napi::Object exports);

    private:
        int graph[200][200];
        void SetNode(const Napi::CallbackInfo &info);
        Napi::Value GetNode(const Napi::CallbackInfo &info);
};

#endif
