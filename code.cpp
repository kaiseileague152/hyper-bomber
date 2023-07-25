# include <Siv3D.hpp> // OpenSiv3D v0.6.10
void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 画像ファイルからテクスチャを作成する | Create a texture from an image file
	const Texture texture{ U"example/windmill.png" };

	// 絵文字からテクスチャを作成する | Create a texture from an emoji
	const Texture emoji{ U"🦖"_emoji };

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// テキストに含まれる絵文字のためのフォントを作成し、font に追加する | Create a font for emojis in text and add it to font as a fallback
	const Font emojiFont{ 48, Typeface::ColorEmoji };
	font.addFallback(emojiFont);
	double count = 40.0;
	bool x = false;
	int now = 1;
	double x1 = 180;
	double x2 = 180;
	double x3 = 180;
	double x4 = 180;
	double x5 = 180;
	bool cl = false;
	bool ov = false;
	double cool = 0;
	while (System::Update())
	{
		double deltaTime = Scene::DeltaTime();
		// 指定した範囲内にテキストを描く | Draw text within a specified area
		font(U"問　題").draw(32, Rect{ 20, 20, 600, 200 }, Palette::Black);
		font(U"開成の運動会競技、10個答えよ(仮)").draw(32, Rect{ 100, 80, 600, 200 }, Palette::Black);
		// 長方形を描く | Draw a rectangle
		Rect{ 120, 180, 80, 400 }.draw(ColorF{ 1.0, 0.6, 0.8});
		Rect{ 240, 180, 80, 400 }.draw(ColorF{ 1.0, 0.8, 0.0});
		Rect{ 360, 180, 80, 400 }.draw(ColorF{ 1.0, 1.0, 0.6});
		Rect{ 480, 180, 80, 400 }.draw(ColorF{ 0.8, 1.0, 0.8});
		Rect{ 600, 180, 80, 400 }.draw(ColorF{ 0.6, 0.8, 1.0});

		// 角丸長方形を描く | Draw a rounded rectangle
		RoundRect{ 100, x1, 120, 20, 20 }.draw(ColorF{ 1.0, 1.0, 1.0 });
		RoundRect{ 220, x2, 120, 20, 20 }.draw(ColorF{ 1.0, 1.0, 1.0 });
		RoundRect{ 340, x3, 120, 20, 20 }.draw(ColorF{ 1.0, 1.0, 1.0 });
		RoundRect{ 460, x4, 120, 20, 20 }.draw(ColorF{ 1.0, 1.0, 1.0 });
		RoundRect{ 580, x5, 120, 20, 20 }.draw(ColorF{ 1.0, 1.0, 1.0 });
		if(KeyX.pressed()){
			if (x==false) {
				x=true;
			}
			else {
				x = false;
			}
		}
		bool o = false;
		bool b = true;
		if (KeyO.pressed()&&cool>=1) {
			if (o == false) {
				o = true;
			}
			else {
				o = false;
			}
		}
		cool += deltaTime;
		if (cl) {
			font(U"GAME CLEAR").draw(80, Rect{ 20, 20, 600, 600 }, Palette::White);

		}
		if (ov) {
			font(U"GAME OVER").draw(80, Rect{ 20, 20, 600, 600 }, Palette::Red);
			x = false;

		}
		if (x) {
			count -= deltaTime;
			if (count <= 0) {
				ov = true;
			}
			if (now == 1) {
				if (o&&b) {
					now++;
					b = false;
					x2 = x1;
					cool = 0;
				}
				else x1 += deltaTime * 10;
			}
			if (now == 2) {
				if (o&&b) {
					now++;
					b = false;
					x3 = x2;
					cool = 0;

				}
				else x2 += deltaTime * 10;
			}
			if (now == 3) {
				if (o&&b) {
					now++;
					b = false;
					x4 = x3;
					cool = 0;

				}
				else x3 += deltaTime * 10;

			}
			if (now == 4) {
				if (o&&b) {
					now++;
					b = false;
					x5 = x4;
					cool = 0;

				}
				else x4 += deltaTime * 10;

			}
			if (now == 5) {
				if (o&&b) {
					now++;
					b = false;
					x4 = x5;
					x3 = x4;
					x2 = x3;
					x1 = x2;
					cool = 0;

				}
				else x5 += deltaTime * 10;

			}
			if (now == 6) {
				if (o&&b) {
					now++;
					b = false;
					x4 = x5;
					cool = 0;

				}
				else x5 += deltaTime * 10;

			}
			if (now == 7) {
				if (o&&b) {
					now++;
					b = false;
					x3 = x4;
					cool = 0;

				}
				else x4 += deltaTime * 10;

			}
			if (now == 8) {
				if (o&&b) {
					now++;
					b = false;
					x2 = x3;
					cool = 0;

				}
				else x3 += deltaTime * 10;

			}
			if (now == 9) {
				if (o&&b) {
					now++;
					b = false;
					x1 = x2;
					cool = 0;

				}
				else x2 += deltaTime * 10;

			}
			if (now == 10) {
				if (o&&b) {
					x = false;
					cl = true;
					cool = 0;

				}
				else x1 += deltaTime * 10;

			}
		}
	}
}
