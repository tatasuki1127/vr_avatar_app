﻿#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>



struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C;
struct String_t;
struct iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1;

IL2CPP_EXTERN_C RuntimeClass* Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25_RuntimeMethod_var;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_tFB72A311ABC9BAA04E86FBC9F16169DEC66E46AC 
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1  : public RuntimeObject
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69 
{
	float* ___Ap;
	int32_t ___AM;
	int32_t ___AN;
	float* ___Bp;
	int32_t ___BM;
	int32_t ___BN;
	float* ___Cp;
	int32_t ___CM;
	int32_t ___CN;
	int32_t ___bs;
	bool ___transposeA;
	bool ___transposeB;
};
struct SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_pinvoke
{
	float* ___Ap;
	int32_t ___AM;
	int32_t ___AN;
	float* ___Bp;
	int32_t ___BM;
	int32_t ___BN;
	float* ___Cp;
	int32_t ___CM;
	int32_t ___CN;
	int32_t ___bs;
	int32_t ___transposeA;
	int32_t ___transposeB;
};
struct SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_com
{
	float* ___Ap;
	int32_t ___AM;
	int32_t ___AN;
	float* ___Bp;
	int32_t ___BM;
	int32_t ___BN;
	float* ___Cp;
	int32_t ___CM;
	int32_t ___CN;
	int32_t ___bs;
	int32_t ___transposeA;
	int32_t ___transposeB;
};
struct RuntimePlatform_t9A8AAF204603076FCAAECCCC05DA386AEE7BF66E 
{
	int32_t ___value__;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25_gshared (SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69 ___0_jobData, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_dependsOn, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Application_get_platform_m59EF7D6155D18891B24767F83F388160B1FF2138 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void iOSBLAS_iossgemm_m36A3FF15A6E08E4B6597BCBFFE0FC3065C4BBB82 (float* ___0_Ap, int32_t ___1_AM, int32_t ___2_AN, float* ___3_Bp, int32_t ___4_BM, int32_t ___5_BN, float* ___6_Cp, int32_t ___7_CM, int32_t ___8_CN, int32_t ___9_bs, bool ___10_transposeA, bool ___11_transposeB, const RuntimeMethod* method) ;
inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25 (SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69 ___0_jobData, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_dependsOn, const RuntimeMethod* method)
{
	return ((  JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 (*) (SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, const RuntimeMethod*))IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25_gshared)(___0_jobData, ___1_dependsOn, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void SGEMMJob_Execute_m657BD67029964DB4B8253EB2A9F5A0C475D7EC36 (SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69* IL2CPP_PARAMETER_RESTRICT __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C void DEFAULT_CALL iossgemm(float*, int32_t, int32_t, float*, int32_t, int32_t, float*, int32_t, int32_t, int32_t, int32_t, int32_t);
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void iOSBLAS_iossgemm_m36A3FF15A6E08E4B6597BCBFFE0FC3065C4BBB82 (float* ___0_Ap, int32_t ___1_AM, int32_t ___2_AN, float* ___3_Bp, int32_t ___4_BM, int32_t ___5_BN, float* ___6_Cp, int32_t ___7_CM, int32_t ___8_CN, int32_t ___9_bs, bool ___10_transposeA, bool ___11_transposeB, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (float*, int32_t, int32_t, float*, int32_t, int32_t, float*, int32_t, int32_t, int32_t, int32_t, int32_t);

	reinterpret_cast<PInvokeFunc>(iossgemm)(___0_Ap, ___1_AM, ___2_AN, ___3_Bp, ___4_BM, ___5_BN, ___6_Cp, ___7_CM, ___8_CN, ___9_bs, static_cast<int32_t>(___10_transposeA), static_cast<int32_t>(___11_transposeB));

}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool iOSBLAS_IsNative_mDF27F867CCDD27867623EC1F31A9F44C76D362DA (iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1* __this, const RuntimeMethod* method) 
{
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool iOSBLAS_IsCurrentPlatformSupported_m81D753CFF8A6430CB4A3B712A3AF58CEF84AB1B6 (iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var);
		int32_t L_0;
		L_0 = Application_get_platform_m59EF7D6155D18891B24767F83F388160B1FF2138(NULL);
		return (bool)((((int32_t)L_0) == ((int32_t)8))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void iOSBLAS_SGEMM_m72EA5113105105F918F8D92B563A4B5B12D0ECD7 (iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1* __this, float* ___0_Ap, int32_t ___1_AM, int32_t ___2_AN, float* ___3_Bp, int32_t ___4_BM, int32_t ___5_BN, float* ___6_Cp, int32_t ___7_CM, int32_t ___8_CN, int32_t ___9_bs, bool ___10_transposeA, bool ___11_transposeB, const RuntimeMethod* method) 
{
	{
		float* L_0 = ___0_Ap;
		int32_t L_1 = ___1_AM;
		int32_t L_2 = ___2_AN;
		float* L_3 = ___3_Bp;
		int32_t L_4 = ___4_BM;
		int32_t L_5 = ___5_BN;
		float* L_6 = ___6_Cp;
		int32_t L_7 = ___7_CM;
		int32_t L_8 = ___8_CN;
		int32_t L_9 = ___9_bs;
		bool L_10 = ___10_transposeA;
		bool L_11 = ___11_transposeB;
		iOSBLAS_iossgemm_m36A3FF15A6E08E4B6597BCBFFE0FC3065C4BBB82(L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, L_10, L_11, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 iOSBLAS_ScheduleSGEMM_m8B141DABB00A042E486E3CCFCA8827446C8B7E2C (iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_dependsOn, float* ___1_Ap, int32_t ___2_AM, int32_t ___3_AN, float* ___4_Bp, int32_t ___5_BM, int32_t ___6_BN, float* ___7_Cp, int32_t ___8_CM, int32_t ___9_CN, int32_t ___10_bs, bool ___11_transposeA, bool ___12_transposeB, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69));
		float* L_0 = ___1_Ap;
		(&V_0)->___Ap = L_0;
		int32_t L_1 = ___2_AM;
		(&V_0)->___AM = L_1;
		int32_t L_2 = ___3_AN;
		(&V_0)->___AN = L_2;
		float* L_3 = ___4_Bp;
		(&V_0)->___Bp = L_3;
		int32_t L_4 = ___5_BM;
		(&V_0)->___BM = L_4;
		int32_t L_5 = ___6_BN;
		(&V_0)->___BN = L_5;
		float* L_6 = ___7_Cp;
		(&V_0)->___Cp = L_6;
		int32_t L_7 = ___8_CM;
		(&V_0)->___CM = L_7;
		int32_t L_8 = ___9_CN;
		(&V_0)->___CN = L_8;
		bool L_9 = ___11_transposeA;
		(&V_0)->___transposeA = L_9;
		bool L_10 = ___12_transposeB;
		(&V_0)->___transposeB = L_10;
		int32_t L_11 = ___10_bs;
		(&V_0)->___bs = L_11;
		SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69 L_12 = V_0;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_13 = ___0_dependsOn;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_14;
		L_14 = IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25(L_12, L_13, IJobExtensions_Schedule_TisSGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_mA4A07AA2606B0DB18AA616B4CF910FC6CCE7AD25_RuntimeMethod_var);
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void iOSBLAS__ctor_m4F0BAADA2447FB8F1C33DAC68AB6A78B9190D1AA (iOSBLAS_t8A618D8991BF9E2FC5A03B270C68C066026F2DC1* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshal_pinvoke(const SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69& unmarshaled, SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_pinvoke& marshaled)
{
	marshaled.___Ap = unmarshaled.___Ap;
	marshaled.___AM = unmarshaled.___AM;
	marshaled.___AN = unmarshaled.___AN;
	marshaled.___Bp = unmarshaled.___Bp;
	marshaled.___BM = unmarshaled.___BM;
	marshaled.___BN = unmarshaled.___BN;
	marshaled.___Cp = unmarshaled.___Cp;
	marshaled.___CM = unmarshaled.___CM;
	marshaled.___CN = unmarshaled.___CN;
	marshaled.___bs = unmarshaled.___bs;
	marshaled.___transposeA = static_cast<int32_t>(unmarshaled.___transposeA);
	marshaled.___transposeB = static_cast<int32_t>(unmarshaled.___transposeB);
}
IL2CPP_EXTERN_C void SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshal_pinvoke_back(const SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_pinvoke& marshaled, SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69& unmarshaled)
{
	unmarshaled.___Ap = marshaled.___Ap;
	int32_t unmarshaledAM_temp_1 = 0;
	unmarshaledAM_temp_1 = marshaled.___AM;
	unmarshaled.___AM = unmarshaledAM_temp_1;
	int32_t unmarshaledAN_temp_2 = 0;
	unmarshaledAN_temp_2 = marshaled.___AN;
	unmarshaled.___AN = unmarshaledAN_temp_2;
	unmarshaled.___Bp = marshaled.___Bp;
	int32_t unmarshaledBM_temp_4 = 0;
	unmarshaledBM_temp_4 = marshaled.___BM;
	unmarshaled.___BM = unmarshaledBM_temp_4;
	int32_t unmarshaledBN_temp_5 = 0;
	unmarshaledBN_temp_5 = marshaled.___BN;
	unmarshaled.___BN = unmarshaledBN_temp_5;
	unmarshaled.___Cp = marshaled.___Cp;
	int32_t unmarshaledCM_temp_7 = 0;
	unmarshaledCM_temp_7 = marshaled.___CM;
	unmarshaled.___CM = unmarshaledCM_temp_7;
	int32_t unmarshaledCN_temp_8 = 0;
	unmarshaledCN_temp_8 = marshaled.___CN;
	unmarshaled.___CN = unmarshaledCN_temp_8;
	int32_t unmarshaledbs_temp_9 = 0;
	unmarshaledbs_temp_9 = marshaled.___bs;
	unmarshaled.___bs = unmarshaledbs_temp_9;
	bool unmarshaledtransposeA_temp_10 = false;
	unmarshaledtransposeA_temp_10 = static_cast<bool>(marshaled.___transposeA);
	unmarshaled.___transposeA = unmarshaledtransposeA_temp_10;
	bool unmarshaledtransposeB_temp_11 = false;
	unmarshaledtransposeB_temp_11 = static_cast<bool>(marshaled.___transposeB);
	unmarshaled.___transposeB = unmarshaledtransposeB_temp_11;
}
IL2CPP_EXTERN_C void SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshal_pinvoke_cleanup(SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshal_com(const SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69& unmarshaled, SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_com& marshaled)
{
	marshaled.___Ap = unmarshaled.___Ap;
	marshaled.___AM = unmarshaled.___AM;
	marshaled.___AN = unmarshaled.___AN;
	marshaled.___Bp = unmarshaled.___Bp;
	marshaled.___BM = unmarshaled.___BM;
	marshaled.___BN = unmarshaled.___BN;
	marshaled.___Cp = unmarshaled.___Cp;
	marshaled.___CM = unmarshaled.___CM;
	marshaled.___CN = unmarshaled.___CN;
	marshaled.___bs = unmarshaled.___bs;
	marshaled.___transposeA = static_cast<int32_t>(unmarshaled.___transposeA);
	marshaled.___transposeB = static_cast<int32_t>(unmarshaled.___transposeB);
}
IL2CPP_EXTERN_C void SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshal_com_back(const SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_com& marshaled, SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69& unmarshaled)
{
	unmarshaled.___Ap = marshaled.___Ap;
	int32_t unmarshaledAM_temp_1 = 0;
	unmarshaledAM_temp_1 = marshaled.___AM;
	unmarshaled.___AM = unmarshaledAM_temp_1;
	int32_t unmarshaledAN_temp_2 = 0;
	unmarshaledAN_temp_2 = marshaled.___AN;
	unmarshaled.___AN = unmarshaledAN_temp_2;
	unmarshaled.___Bp = marshaled.___Bp;
	int32_t unmarshaledBM_temp_4 = 0;
	unmarshaledBM_temp_4 = marshaled.___BM;
	unmarshaled.___BM = unmarshaledBM_temp_4;
	int32_t unmarshaledBN_temp_5 = 0;
	unmarshaledBN_temp_5 = marshaled.___BN;
	unmarshaled.___BN = unmarshaledBN_temp_5;
	unmarshaled.___Cp = marshaled.___Cp;
	int32_t unmarshaledCM_temp_7 = 0;
	unmarshaledCM_temp_7 = marshaled.___CM;
	unmarshaled.___CM = unmarshaledCM_temp_7;
	int32_t unmarshaledCN_temp_8 = 0;
	unmarshaledCN_temp_8 = marshaled.___CN;
	unmarshaled.___CN = unmarshaledCN_temp_8;
	int32_t unmarshaledbs_temp_9 = 0;
	unmarshaledbs_temp_9 = marshaled.___bs;
	unmarshaled.___bs = unmarshaledbs_temp_9;
	bool unmarshaledtransposeA_temp_10 = false;
	unmarshaledtransposeA_temp_10 = static_cast<bool>(marshaled.___transposeA);
	unmarshaled.___transposeA = unmarshaledtransposeA_temp_10;
	bool unmarshaledtransposeB_temp_11 = false;
	unmarshaledtransposeB_temp_11 = static_cast<bool>(marshaled.___transposeB);
	unmarshaled.___transposeB = unmarshaledtransposeB_temp_11;
}
IL2CPP_EXTERN_C void SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshal_com_cleanup(SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69_marshaled_com& marshaled)
{
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void SGEMMJob_Execute_m657BD67029964DB4B8253EB2A9F5A0C475D7EC36 (SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69* IL2CPP_PARAMETER_RESTRICT __this, const RuntimeMethod* method) 
{
	{
		float* L_0 = __this->___Ap;
		int32_t L_1 = __this->___AM;
		int32_t L_2 = __this->___AN;
		float* L_3 = __this->___Bp;
		int32_t L_4 = __this->___BM;
		int32_t L_5 = __this->___BN;
		float* L_6 = __this->___Cp;
		int32_t L_7 = __this->___CM;
		int32_t L_8 = __this->___CN;
		int32_t L_9 = __this->___bs;
		bool L_10 = __this->___transposeA;
		bool L_11 = __this->___transposeB;
		iOSBLAS_iossgemm_m36A3FF15A6E08E4B6597BCBFFE0FC3065C4BBB82(L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, L_10, L_11, NULL);
		return;
	}
}
IL2CPP_EXTERN_C  void SGEMMJob_Execute_m657BD67029964DB4B8253EB2A9F5A0C475D7EC36_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, const RuntimeMethod* method)
{
	SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<SGEMMJob_t4295A60A6AE573DAB788A1F6EDE4125C8787CD69*>(__this + _offset);
	SGEMMJob_Execute_m657BD67029964DB4B8253EB2A9F5A0C475D7EC36(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
