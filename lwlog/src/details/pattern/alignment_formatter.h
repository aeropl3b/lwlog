#pragma once

#include <string>

namespace lwlog::details
{
	struct alignment_flag
	{
		static constexpr auto end		{ ":|" };
		static constexpr auto left		{ ":<" };
		static constexpr auto right		{ ":>" };
		static constexpr auto center	{ ":^" };
	};

	struct alignment_specification
	{
		enum class align_side { left, center, right };
		explicit alignment_specification(std::string str);

		char fill_char{};
		align_side side{};
		std::uint8_t width{};
		std::string to_align;
		std::string flag;
	};

	struct alignment_formatter
	{
		static void format(std::string& pattern, const alignment_specification& spec);
		static std::string align(const std::string& to_align, std::uint8_t width,
			char fill_char, alignment_specification::align_side side);

		static std::string align_left(const std::string& to_align, std::uint8_t width, char fill_char);
		static std::string align_right(const std::string& to_align, std::uint8_t width, char fill_char);
		static std::string align_center(const std::string& to_align, std::uint8_t width, char fill_char);
	};
}