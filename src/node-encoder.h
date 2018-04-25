#include <node.h>
#include "encoder.h"
#include <node_object_wrap.h>

#ifndef NODE_ENCODER_H_
#define NODE_ENCODER_H_

using namespace v8;

int WriteNumber(bo_encoder* encoder, double number);
void WriteNumber(Isolate* isolate, bo_encoder* encoder, double number);
void WriteNumber(Isolate* isolate, bo_encoder* encoder, Local<Number> value);

void WriteValue(Isolate* isolate, bo_encoder* encoder, Local<Value> value);
void WriteObject(Isolate* isolate, bo_encoder* encoder, Local<Object> object);

class Encoder : public node::ObjectWrap {
private:
    bo_encoder* encoder;
    Encoder();
    ~Encoder();
    static Persistent<Function> constructor;
    static void New(const FunctionCallbackInfo<Value>& args);
    static void Encode(const FunctionCallbackInfo<Value>& args);
    Local<Object> holder;

public:
    static void Init(Isolate* isolate);
    static void NewInstance(const FunctionCallbackInfo<Value>& args);
    static void CreateObject(const FunctionCallbackInfo<Value>& args);

    void SetCurrentHolder(Local<Object> holder);
    Local<Object> GetHolder();

    void CopyContents(void* buffer);
    void WriteInt8(int8_t n);
    void WriteDoubleLE(double n);
    void WriteUInt8(uint8_t n);
    void WriteUInt16LE(uint16_t n);
    void WriteUInt32LE(uint32_t n);
    void WriteInt16LE(int16_t n);
    void WriteInt32LE(int32_t n);
    void PushBuffer(size_t string_length, uint8_t* buffer);
};

#endif