/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class vlab_cs_ucsb_edu_DriverProxy */

#ifndef _Included_vlab_cs_ucsb_edu_DriverProxy
#define _Included_vlab_cs_ucsb_edu_DriverProxy
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    initABC
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_initABC
  (JNIEnv *, jobject, jint);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    setOption
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_setOption__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    setOption
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_setOption__ILjava_lang_String_2
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    isSatisfiable
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_isSatisfiable
  (JNIEnv *, jobject, jstring);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    countVariable
 * Signature: (Ljava/lang/String;J)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_countVariable__Ljava_lang_String_2J
  (JNIEnv *, jobject, jstring, jlong);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    countInts
 * Signature: (J)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_countInts__J
  (JNIEnv *, jobject, jlong);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    countStrs
 * Signature: (J)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_countStrs__J
  (JNIEnv *, jobject, jlong);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    count
 * Signature: (JJ)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_count__JJ
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    getModelCounterForVariable
 * Signature: (Ljava/lang/String;)[B
 */
JNIEXPORT jbyteArray JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_getModelCounterForVariable
  (JNIEnv *, jobject, jstring);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    getModelCounter
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_getModelCounter
  (JNIEnv *, jobject);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    countVariable
 * Signature: (Ljava/lang/String;J[B)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_countVariable__Ljava_lang_String_2J_3B
  (JNIEnv *, jobject, jstring, jlong, jbyteArray);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    countInts
 * Signature: (J[B)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_countInts__J_3B
  (JNIEnv *, jobject, jlong, jbyteArray);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    countStrs
 * Signature: (J[B)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_countStrs__J_3B
  (JNIEnv *, jobject, jlong, jbyteArray);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    count
 * Signature: (JJ[B)Ljava/math/BigInteger;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_count__JJ_3B
  (JNIEnv *, jobject, jlong, jlong, jbyteArray);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    printResultAutomaton
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_printResultAutomaton__
  (JNIEnv *, jobject);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    printResultAutomaton
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_printResultAutomaton__Ljava_lang_String_2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    getSatisfyingExamples
 * Signature: ()Ljava/util/Map;
 */
JNIEXPORT jobject JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_getSatisfyingExamples
  (JNIEnv *, jobject);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    reset
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_reset
  (JNIEnv *, jobject);

/*
 * Class:     vlab_cs_ucsb_edu_DriverProxy
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_vlab_cs_ucsb_edu_DriverProxy_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
