﻿#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>



struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410;
struct Exception_t;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* D_t3F7E1E992D075ACCE6A335C3DDC5C2273EC97401_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral8DCC3AF6F2D842D9485DCB78474DB5CA4BB24D28;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_tFAD613B78CF3D09400B8E6C67202C042CB90F56E 
{
};
struct BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410  : public RuntimeObject
{
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
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
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
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
struct MatrixMultiplyJob_t3862DAFD1852F61A839746FCE9A98F23E2D39CC7 
{
	float* ___A;
	int32_t ___AM;
	int32_t ___AN;
	float* ___B;
	int32_t ___BM;
	int32_t ___BN;
	float* ___C;
	int32_t ___CM;
	int32_t ___CN;
	bool ___transposeA;
	bool ___transposeB;
	int32_t ___blockSizeM;
	int32_t ___blockSizeN;
	int32_t ___blockSizeK;
};
struct MatrixMultiplyJob_t3862DAFD1852F61A839746FCE9A98F23E2D39CC7_marshaled_pinvoke
{
	float* ___A;
	int32_t ___AM;
	int32_t ___AN;
	float* ___B;
	int32_t ___BM;
	int32_t ___BN;
	float* ___C;
	int32_t ___CM;
	int32_t ___CN;
	int32_t ___transposeA;
	int32_t ___transposeB;
	int32_t ___blockSizeM;
	int32_t ___blockSizeN;
	int32_t ___blockSizeK;
};
struct MatrixMultiplyJob_t3862DAFD1852F61A839746FCE9A98F23E2D39CC7_marshaled_com
{
	float* ___A;
	int32_t ___AM;
	int32_t ___AN;
	float* ___B;
	int32_t ___BM;
	int32_t ___BN;
	float* ___C;
	int32_t ___CM;
	int32_t ___CN;
	int32_t ___transposeA;
	int32_t ___transposeB;
	int32_t ___blockSizeM;
	int32_t ___blockSizeN;
	int32_t ___blockSizeK;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void D_Log_mBAFB6B30A6C571C94D9814E4C23C448F02739515 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 BurstBLAS_ScheduleSGEMM_m3AE958567CBCE4EB983163893F28E01E966892DF (BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_dependsOn, float* ___1_Ap, int32_t ___2_AM, int32_t ___3_AN, float* ___4_Bp, int32_t ___5_BM, int32_t ___6_BN, float* ___7_Cp, int32_t ___8_CM, int32_t ___9_CN, int32_t ___10_bs, bool ___11_transposeA, bool ___12_transposeB, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JobHandle_Complete_mDCED35A125AAB37EDDAB2E31C805B4904B614A4A (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 MatrixMultiplyJob_Schedule_mDF462F5A4B0F8F30ABD8568AC9308ECA61B7828B (MatrixMultiplyJob_t3862DAFD1852F61A839746FCE9A98F23E2D39CC7* IL2CPP_PARAMETER_RESTRICT __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BurstBLAS_IsNative_m3287EC2915EE4B0A5A26B778413EBED790C2EEA9 (BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BurstBLAS_IsCurrentPlatformSupported_m9EB46353878145AEE68463B84441CC5BB81949A5 (BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410* __this, const RuntimeMethod* method) 
{
	Exception_t* V_0 = NULL;
	bool V_1 = false;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	try
	{
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0002;
		}
		throw e;
	}

CATCH_0002:
	{
		Exception_t* L_0 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_0 = L_0;
		Type_t* L_1;
		L_1 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(__this, NULL);
		Exception_t* L_2 = V_0;
		String_t* L_3;
		L_3 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral8DCC3AF6F2D842D9485DCB78474DB5CA4BB24D28)), L_1, L_2, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&D_t3F7E1E992D075ACCE6A335C3DDC5C2273EC97401_il2cpp_TypeInfo_var)));
		D_Log_mBAFB6B30A6C571C94D9814E4C23C448F02739515(L_3, NULL);
		V_1 = (bool)0;
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_001f;
	}

IL_001d:
	{
		return (bool)1;
	}

IL_001f:
	{
		bool L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BurstBLAS_SGEMM_m8C7AE0D5E0B47AEB8A5BFDF47B2DDB34940A2BDE (BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410* __this, float* ___0_Ap, int32_t ___1_AM, int32_t ___2_AN, float* ___3_Bp, int32_t ___4_BM, int32_t ___5_BN, float* ___6_Cp, int32_t ___7_CM, int32_t ___8_CN, int32_t ___9_bs, bool ___10_transposeA, bool ___11_transposeB, const RuntimeMethod* method) 
{
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_0;
	memset((&V_0), 0, sizeof(V_0));
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_0 = V_0;
		float* L_1 = ___0_Ap;
		int32_t L_2 = ___1_AM;
		int32_t L_3 = ___2_AN;
		float* L_4 = ___3_Bp;
		int32_t L_5 = ___4_BM;
		int32_t L_6 = ___5_BN;
		float* L_7 = ___6_Cp;
		int32_t L_8 = ___7_CM;
		int32_t L_9 = ___8_CN;
		int32_t L_10 = ___9_bs;
		bool L_11 = ___10_transposeA;
		bool L_12 = ___11_transposeB;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_13;
		L_13 = BurstBLAS_ScheduleSGEMM_m3AE958567CBCE4EB983163893F28E01E966892DF(__this, L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, L_10, L_11, L_12, NULL);
		V_1 = L_13;
		JobHandle_Complete_mDCED35A125AAB37EDDAB2E31C805B4904B614A4A((&V_1), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 BurstBLAS_ScheduleSGEMM_m3AE958567CBCE4EB983163893F28E01E966892DF (BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_dependsOn, float* ___1_Ap, int32_t ___2_AM, int32_t ___3_AN, float* ___4_Bp, int32_t ___5_BM, int32_t ___6_BN, float* ___7_Cp, int32_t ___8_CM, int32_t ___9_CN, int32_t ___10_bs, bool ___11_transposeA, bool ___12_transposeB, const RuntimeMethod* method) 
{
	MatrixMultiplyJob_t3862DAFD1852F61A839746FCE9A98F23E2D39CC7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MatrixMultiplyJob_t3862DAFD1852F61A839746FCE9A98F23E2D39CC7));
		float* L_0 = ___1_Ap;
		(&V_0)->___A = L_0;
		int32_t L_1 = ___2_AM;
		(&V_0)->___AM = L_1;
		int32_t L_2 = ___3_AN;
		(&V_0)->___AN = L_2;
		float* L_3 = ___4_Bp;
		(&V_0)->___B = L_3;
		int32_t L_4 = ___5_BM;
		(&V_0)->___BM = L_4;
		int32_t L_5 = ___6_BN;
		(&V_0)->___BN = L_5;
		float* L_6 = ___7_Cp;
		(&V_0)->___C = L_6;
		int32_t L_7 = ___8_CM;
		(&V_0)->___CM = L_7;
		int32_t L_8 = ___9_CN;
		(&V_0)->___CN = L_8;
		bool L_9 = ___11_transposeA;
		(&V_0)->___transposeA = L_9;
		bool L_10 = ___12_transposeB;
		(&V_0)->___transposeB = L_10;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_11 = ___0_dependsOn;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_12;
		L_12 = MatrixMultiplyJob_Schedule_mDF462F5A4B0F8F30ABD8568AC9308ECA61B7828B((&V_0), L_11, NULL);
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BurstBLAS__ctor_m0819B7915681A03944BB49E7B6B04EFC2F876151 (BurstBLAS_t1FE587385A9E0E805D3A85EC9251B333CBF55410* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
