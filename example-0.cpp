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

LoginScreen::LoginScreen(){
  //Setting up the window
  property_title() = "BioDB";
  property_default_width() = 1280;
  property_default_height() = 720;
  property_name() = "MainWindow";

  //Setting up the Log in button
  LogInbtn.signal_clicked().connect( sigc::mem_fun(*this, &LoginScreen::on_button_clicked) );
  LogInbtn.set_label("Log in");

  //Setting up the labels
  BioDBLabel.set_text("BioDB");
  Usernamelb.set_text("Username:");
  Passwordlb.set_text("Password:");

  //The window's layout
  layout.put(BioDBLabel, 100, 100);
  layout.put(Usernamelb, 100, 150);
  layout.put(Usernametb, 100, 180);
  layout.put(Passwordlb, 100, 230);
  layout.put(Passwordtb, 100, 260);
  layout.put(LogInbtn, 100, 310);
  add(layout);

  show_all_children();

  //Load the window's css
  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, "theme.css", NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void LoginScreen::on_button_clicked()
{
  std::cout << "Username: " << Usernametb.get_text() << " -- Password: " << Passwordtb.get_text() << std::endl;
}

int main (int argc, char **argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.gtkmm.BioDB");

  LoginScreen LS;

  return app->run(LS);
}