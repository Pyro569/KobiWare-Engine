use druid::widget::Label;
use druid::widget::{Container, Flex, Split};
use druid::Color;
use druid::{AppLauncher, Widget, WindowDesc};

fn build_ui() -> impl Widget<()> {
    Split::columns(
        Container::new(
            Flex::column()
                .with_flex_child(Label::new("2D"), 1.0)
                .with_flex_child(Label::new("Raycaster"), 1.0)
                .with_flex_child(Label::new("3D"), 1.0)
                .with_flex_child(Label::new("Build"), 1.0),
        )
        .border(Color::grey(0.6), 2.0),
        Container::new(
            Flex::column()
                .with_flex_child(Label::new("Button placeholder"), 1.0)
                .with_flex_child(Label::new("Textbox placeholder"), 1.0),
        )
        .border(Color::grey(0.6), 2.0),
    )
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
