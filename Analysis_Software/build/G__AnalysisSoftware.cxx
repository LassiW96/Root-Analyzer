// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__AnalysisSoftware
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
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/FileHandler.h"
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/AnalysisManager.h"
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/GeneratePlots.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *FileHandler_Dictionary();
   static void FileHandler_TClassManip(TClass*);
   static void *new_FileHandler(void *p = nullptr);
   static void *newArray_FileHandler(Long_t size, void *p);
   static void delete_FileHandler(void *p);
   static void deleteArray_FileHandler(void *p);
   static void destruct_FileHandler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FileHandler*)
   {
      ::FileHandler *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::FileHandler));
      static ::ROOT::TGenericClassInfo 
         instance("FileHandler", "FileHandler.h", 34,
                  typeid(::FileHandler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &FileHandler_Dictionary, isa_proxy, 4,
                  sizeof(::FileHandler) );
      instance.SetNew(&new_FileHandler);
      instance.SetNewArray(&newArray_FileHandler);
      instance.SetDelete(&delete_FileHandler);
      instance.SetDeleteArray(&deleteArray_FileHandler);
      instance.SetDestructor(&destruct_FileHandler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FileHandler*)
   {
      return GenerateInitInstanceLocal(static_cast<::FileHandler*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::FileHandler*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *FileHandler_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::FileHandler*>(nullptr))->GetClass();
      FileHandler_TClassManip(theClass);
   return theClass;
   }

   static void FileHandler_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GeneratePlots_Dictionary();
   static void GeneratePlots_TClassManip(TClass*);
   static void *new_GeneratePlots(void *p = nullptr);
   static void *newArray_GeneratePlots(Long_t size, void *p);
   static void delete_GeneratePlots(void *p);
   static void deleteArray_GeneratePlots(void *p);
   static void destruct_GeneratePlots(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GeneratePlots*)
   {
      ::GeneratePlots *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::GeneratePlots));
      static ::ROOT::TGenericClassInfo 
         instance("GeneratePlots", "GeneratePlots.h", 16,
                  typeid(::GeneratePlots), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GeneratePlots_Dictionary, isa_proxy, 4,
                  sizeof(::GeneratePlots) );
      instance.SetNew(&new_GeneratePlots);
      instance.SetNewArray(&newArray_GeneratePlots);
      instance.SetDelete(&delete_GeneratePlots);
      instance.SetDeleteArray(&deleteArray_GeneratePlots);
      instance.SetDestructor(&destruct_GeneratePlots);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GeneratePlots*)
   {
      return GenerateInitInstanceLocal(static_cast<::GeneratePlots*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::GeneratePlots*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GeneratePlots_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::GeneratePlots*>(nullptr))->GetClass();
      GeneratePlots_TClassManip(theClass);
   return theClass;
   }

   static void GeneratePlots_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AnalysisManager_Dictionary();
   static void AnalysisManager_TClassManip(TClass*);
   static void *new_AnalysisManager(void *p = nullptr);
   static void *newArray_AnalysisManager(Long_t size, void *p);
   static void delete_AnalysisManager(void *p);
   static void deleteArray_AnalysisManager(void *p);
   static void destruct_AnalysisManager(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AnalysisManager*)
   {
      ::AnalysisManager *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AnalysisManager));
      static ::ROOT::TGenericClassInfo 
         instance("AnalysisManager", "AnalysisManager.h", 19,
                  typeid(::AnalysisManager), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AnalysisManager_Dictionary, isa_proxy, 4,
                  sizeof(::AnalysisManager) );
      instance.SetNew(&new_AnalysisManager);
      instance.SetNewArray(&newArray_AnalysisManager);
      instance.SetDelete(&delete_AnalysisManager);
      instance.SetDeleteArray(&deleteArray_AnalysisManager);
      instance.SetDestructor(&destruct_AnalysisManager);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AnalysisManager*)
   {
      return GenerateInitInstanceLocal(static_cast<::AnalysisManager*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::AnalysisManager*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AnalysisManager_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::AnalysisManager*>(nullptr))->GetClass();
      AnalysisManager_TClassManip(theClass);
   return theClass;
   }

   static void AnalysisManager_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_FileHandler(void *p) {
      return  p ? new(p) ::FileHandler : new ::FileHandler;
   }
   static void *newArray_FileHandler(Long_t nElements, void *p) {
      return p ? new(p) ::FileHandler[nElements] : new ::FileHandler[nElements];
   }
   // Wrapper around operator delete
   static void delete_FileHandler(void *p) {
      delete (static_cast<::FileHandler*>(p));
   }
   static void deleteArray_FileHandler(void *p) {
      delete [] (static_cast<::FileHandler*>(p));
   }
   static void destruct_FileHandler(void *p) {
      typedef ::FileHandler current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::FileHandler

namespace ROOT {
   // Wrappers around operator new
   static void *new_GeneratePlots(void *p) {
      return  p ? new(p) ::GeneratePlots : new ::GeneratePlots;
   }
   static void *newArray_GeneratePlots(Long_t nElements, void *p) {
      return p ? new(p) ::GeneratePlots[nElements] : new ::GeneratePlots[nElements];
   }
   // Wrapper around operator delete
   static void delete_GeneratePlots(void *p) {
      delete (static_cast<::GeneratePlots*>(p));
   }
   static void deleteArray_GeneratePlots(void *p) {
      delete [] (static_cast<::GeneratePlots*>(p));
   }
   static void destruct_GeneratePlots(void *p) {
      typedef ::GeneratePlots current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::GeneratePlots

namespace ROOT {
   // Wrappers around operator new
   static void *new_AnalysisManager(void *p) {
      return  p ? new(p) ::AnalysisManager : new ::AnalysisManager;
   }
   static void *newArray_AnalysisManager(Long_t nElements, void *p) {
      return p ? new(p) ::AnalysisManager[nElements] : new ::AnalysisManager[nElements];
   }
   // Wrapper around operator delete
   static void delete_AnalysisManager(void *p) {
      delete (static_cast<::AnalysisManager*>(p));
   }
   static void deleteArray_AnalysisManager(void *p) {
      delete [] (static_cast<::AnalysisManager*>(p));
   }
   static void destruct_AnalysisManager(void *p) {
      typedef ::AnalysisManager current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::AnalysisManager

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
  void TriggerDictionaryInitialization_libAnalysisSoftware_Impl() {
    static const char* headers[] = {
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/FileHandler.h",
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/AnalysisManager.h",
"/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/GeneratePlots.h",
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
#line 1 "libAnalysisSoftware dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/FileHandler.h")))  FileHandler;
class __attribute__((annotate("$clingAutoload$GeneratePlots.h")))  __attribute__((annotate("$clingAutoload$/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/AnalysisManager.h")))  GeneratePlots;
class __attribute__((annotate("$clingAutoload$/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/AnalysisManager.h")))  AnalysisManager;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libAnalysisSoftware dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/FileHandler.h"
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/AnalysisManager.h"
#include "/home/lasitha/Root_projects/root-on-vscode/Analysis_Software/include/GeneratePlots.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"AnalysisManager", payloadCode, "@",
"FileHandler", payloadCode, "@",
"GeneratePlots", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libAnalysisSoftware",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libAnalysisSoftware_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libAnalysisSoftware_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libAnalysisSoftware() {
  TriggerDictionaryInitialization_libAnalysisSoftware_Impl();
}
