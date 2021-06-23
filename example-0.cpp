#include <gtkmm.h>
#include <iostream>
#include "Source_Code/LoginScreen.cpp"

int main (int argc, char **argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.gtkmm.BioDB");

  LoginScreen LS;

  return app->run(LS);
}