use druid::widget::Label;
use druid::{AppLauncher, Widget, WindowDesc};

fn build_ui() -> impl Widget<()> {
    Label::new("KobiWare Engine GUI")
}

fn main() {
    let main_window = WindowDesc::new(build_ui())
        .window_size((600.0, 400.0))
        .title("KobiWare Engine GUI");
    let initial_data = ();

    AppLauncher::with_window(main_window)
        .launch(initial_data)
        .expect("Failed to launch application");
}
