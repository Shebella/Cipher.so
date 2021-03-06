//
// Created by 林帅斌 on 2017/12/7.
//

#include "include/cipher-lib.h"
#include "include/extern-keys.h"

map<string, string> _map;

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}

jstring
Java_net_idik_lib_cipher_so_CipherClient_getString(JNIEnv *env, jobject instance, jstring key_) {
    const char *key = env->GetStringUTFChars(key_, 0);
    string keyStr(key);
    string value = _map[keyStr];
    env->ReleaseStringUTFChars(key_, key);
    return env->NewStringUTF(value.c_str());
}

void Java_net_idik_lib_cipher_so_CipherClient_init(JNIEnv *env, jclass type) {
    LOAD_MAP(_map);
}
