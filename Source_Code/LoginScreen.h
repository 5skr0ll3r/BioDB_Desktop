#ifndef LoginScreen_H
#define LoginScreen_H

#include <gtkmm.h>
#include <iostream>


class LoginScreen : public Gtk::Window{
public:
  LoginScreen();

  Gtk::Label BioDBLabel;
  Gtk::Label Usernamelb;
  Gtk::Label Passwordlb;
  Gtk::Button LogInbtn;
  Gtk::Fixed layout;
  Gtk::Entry Usernametb;
  Gtk::Entry Passwordtb;
  void on_button_clicked();
};

#endif