#include <node.h>

namespace addon {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Number;

    extern "C" {
        char *hello();
        double add(double *a, double *b);
    }

    void Hello(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, hello()).ToLocalChecked());
    }

    void Add(const FunctionCallbackInfo<Value>& args) {
        double dbl1 = args[0].As<Number>()->Value();
        double dbl2 = args[1].As<Number>()->Value();
        args.GetReturnValue().Set( add(&dbl1, &dbl2) );
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "hello", Hello);
        NODE_SET_METHOD(exports, "add", Add);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}