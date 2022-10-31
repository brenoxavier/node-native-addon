#include <iostream>
#include <string>
#include "graph.h"

// new Graph(size: number)
Graph::Graph(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Graph>(info)
{
    Napi::Env env = info.Env();
    int length = info.Length();

    if (length == 1 && info[0].IsNumber())
    {
        int graphSize = info[0].ToNumber()
            .Int32Value();

        return;            
    }

    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
}

// setNode(x: number, z: number, value: number)
void Graph::SetNode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int length = info.Length();

    if (length >= 2 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber())
    {
        int xPos = info[0].ToNumber()
            .Int32Value();

        int zPos = info[1].ToNumber()
            .Int32Value();

        Napi::Number block = info[2].ToNumber();
        graph[xPos][zPos] = block.Int32Value();

        return;
    }

    Napi::TypeError::New(env, "Object expected").ThrowAsJavaScriptException();
}

// getNode(x: number, z: number)
Napi::Value Graph::GetNode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int length = info.Length();

    if (length >= 1 && info[0].IsNumber() && info[1].IsNumber())
    {
        int xPos = info[0].ToNumber()
            .Int32Value();

        int zPos = info[1].ToNumber()
            .Int32Value();

        return Napi::Number::New(env, graph[xPos][zPos]);
    }

    Napi::TypeError::New(env, "Index expected").ThrowAsJavaScriptException();
}

Napi::Object Graph::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function function = DefineClass(env, "Graph", {
        InstanceMethod("setNode", &Graph::SetNode),
        InstanceMethod("getNode", &Graph::GetNode)});

    exports.Set("Graph", function);

    return exports;
}
