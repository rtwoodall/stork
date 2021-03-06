#include "MrDuckieApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<MrDuckieApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MrDuckieApp::MrDuckieApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MrDuckieApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MrDuckieApp::associateSyntax(_syntax, _action_factory);
}

MrDuckieApp::~MrDuckieApp()
{
}

// External entry point for dynamic application loading
extern "C" void MrDuckieApp__registerApps() { MrDuckieApp::registerApps(); }
void
MrDuckieApp::registerApps()
{
  registerApp(MrDuckieApp);
}

// External entry point for dynamic object registration
extern "C" void MrDuckieApp__registerObjects(Factory & factory) { MrDuckieApp::registerObjects(factory); }
void
MrDuckieApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MrDuckieApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MrDuckieApp::associateSyntax(syntax, action_factory); }
void
MrDuckieApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
