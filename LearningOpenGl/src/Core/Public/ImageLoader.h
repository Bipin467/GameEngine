#pragma once
// ###### To be continued later :) ######
namespace ImageLoader {
	struct AlphaImage {
	public:
		int x, y, r, g, b, a;
	};
	class PNGImage {
	private:
		static PNGImage* m_Instance;
	private:
		PNGImage();
	public:
		static PNGImage* GetInstance();

	};
}