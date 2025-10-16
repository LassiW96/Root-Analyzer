// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__RootAnalyzer
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/RootAnalyzer.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *RootAnalyzer_Dictionary();
   static void RootAnalyzer_TClassManip(TClass*);
   static void *new_RootAnalyzer(void *p = nullptr);
   static void *newArray_RootAnalyzer(Long_t size, void *p);
   static void delete_RootAnalyzer(void *p);
   static void deleteArray_RootAnalyzer(void *p);
   static void destruct_RootAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RootAnalyzer*)
   {
      ::RootAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RootAnalyzer));
      static ::ROOT::TGenericClassInfo 
         instance("RootAnalyzer", "RootAnalyzer.h", 34,
                  typeid(::RootAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RootAnalyzer_Dictionary, isa_proxy, 4,
                  sizeof(::RootAnalyzer) );
      instance.SetNew(&new_RootAnalyzer);
      instance.SetNewArray(&newArray_RootAnalyzer);
      instance.SetDelete(&delete_RootAnalyzer);
      instance.SetDeleteArray(&deleteArray_RootAnalyzer);
      instance.SetDestructor(&destruct_RootAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RootAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::RootAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RootAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RootAnalyzer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::RootAnalyzer*>(nullptr))->GetClass();
      RootAnalyzer_TClassManip(theClass);
   return theClass;
   }

   static void RootAnalyzer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_RootAnalyzer(void *p) {
      return  p ? new(p) ::RootAnalyzer : new ::RootAnalyzer;
   }
   static void *newArray_RootAnalyzer(Long_t nElements, void *p) {
      return p ? new(p) ::RootAnalyzer[nElements] : new ::RootAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_RootAnalyzer(void *p) {
      delete (static_cast<::RootAnalyzer*>(p));
   }
   static void deleteArray_RootAnalyzer(void *p) {
      delete [] (static_cast<::RootAnalyzer*>(p));
   }
   static void destruct_RootAnalyzer(void *p) {
      typedef ::RootAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RootAnalyzer

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = nullptr);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 428,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr))->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete (static_cast<vector<string>*>(p));
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] (static_cast<vector<string>*>(p));
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *maplEstringcOBranchDatagR_Dictionary();
   static void maplEstringcOBranchDatagR_TClassManip(TClass*);
   static void *new_maplEstringcOBranchDatagR(void *p = nullptr);
   static void *newArray_maplEstringcOBranchDatagR(Long_t size, void *p);
   static void delete_maplEstringcOBranchDatagR(void *p);
   static void deleteArray_maplEstringcOBranchDatagR(void *p);
   static void destruct_maplEstringcOBranchDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,BranchData>*)
   {
      map<string,BranchData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,BranchData>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,BranchData>", -2, "map", 102,
                  typeid(map<string,BranchData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOBranchDatagR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,BranchData>) );
      instance.SetNew(&new_maplEstringcOBranchDatagR);
      instance.SetNewArray(&newArray_maplEstringcOBranchDatagR);
      instance.SetDelete(&delete_maplEstringcOBranchDatagR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOBranchDatagR);
      instance.SetDestructor(&destruct_maplEstringcOBranchDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,BranchData> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<string,BranchData>","std::map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, BranchData, std::less<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, BranchData> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<string,BranchData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOBranchDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<string,BranchData>*>(nullptr))->GetClass();
      maplEstringcOBranchDatagR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOBranchDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOBranchDatagR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,BranchData> : new map<string,BranchData>;
   }
   static void *newArray_maplEstringcOBranchDatagR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,BranchData>[nElements] : new map<string,BranchData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOBranchDatagR(void *p) {
      delete (static_cast<map<string,BranchData>*>(p));
   }
   static void deleteArray_maplEstringcOBranchDatagR(void *p) {
      delete [] (static_cast<map<string,BranchData>*>(p));
   }
   static void destruct_maplEstringcOBranchDatagR(void *p) {
      typedef map<string,BranchData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<string,BranchData>

namespace {
  void TriggerDictionaryInitialization_libRootAnalyzer_Impl() {
    static const char* headers[] = {
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/RootAnalyzer.h",
nullptr
    };
    static const char* includePaths[] = {
"/home/lasitha/root/install/include",
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include",
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software",
"/home/lasitha/root/install/include/",
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libRootAnalyzer dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/RootAnalyzer.h")))  RootAnalyzer;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libRootAnalyzer dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/RootAnalyzer.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RootAnalyzer", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libRootAnalyzer",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libRootAnalyzer_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libRootAnalyzer_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libRootAnalyzer() {
  TriggerDictionaryInitialization_libRootAnalyzer_Impl();
}
