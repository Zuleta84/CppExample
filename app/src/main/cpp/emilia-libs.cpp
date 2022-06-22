/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <cstring>
#include <jni.h>
#include <cinttypes>
#include <android/log.h>
#include <string>
#include <emilia.h>

#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, "emilia-libs::", __VA_ARGS__))

extern "C" JNIEXPORT int JNICALL
Java_com_example_myapplication_FirstFragment_callHola(JNIEnv *env, jobject thiz, jint j) {
    // Just for simplicity, we do this right away; correct way would do it in
    // another thread...
    //auto ticks = GetTicks();

    int resultat = hola(j);

    jclass clazz = env->FindClass("com/example/myapplication/FirstFragment");
    jmethodID messageMe = env->GetMethodID(clazz, "messageMe", "(I)I");
    resultat = env->CallIntMethod(thiz, messageMe, resultat);
    //ticks = GetTicks() - ticks;

    //LOGI("calculation time: %" PRIu64, ticks);

    //return env->NewStringUTF("Hello from JNI LIBS!");
    return resultat;
}
