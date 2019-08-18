#pragma once

#include <cstdint>
#include <optional>
#include <ostream>
#include <set>
#include "tgfx/color.hpp"

namespace tgfx
{

/**
 * @brief Allows for easy toggling of multplie certain terminal style codes,
 * and generating an ansi-code to output and apply.
 * 
 */
class style
{
public:
	/// Init
	style();

	/// All possible states for a stylepoint to be set to.
	enum class state : uint8_t
	{
		ON,		 // Turn the style point on.
		OFF,	 // Turn off all of this style point.
		IGNORE   // Ignore the style point.
	};

	/**
	 * @brief Turns text bolding on.
	 * 
	 * @return style& *this
	 */
	style& bold_on();
	/**
	 * @brief Turns text bold off.
	 * 
	 * @return style& *this
	 */
	style& bold_off();
	/**
	 * @brief Leaves text bold as-is.
	 * 
	 * @return style& *this
	 */
	style& bold_ignore();
	/**
	 * @brief Get the state that the bold stylepoint is set to.
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state bold() const;
	/**
	 * @brief Set the specific state the bold stylepoint is set to.
	 * 
	 * @param s The new state of the bold stylepoint.
	 */
	void bold(const state& s);

	/**
	 * @brief Turns faint text on.
	 * 
	 * @remarks Rarely supported by terminals.
	 * 
	 * @return style& 
	 */
	style& faint_on();
	/**
	 * @brief Turn faint text off
	 * 
	 * @return style& *this
	 */
	style& faint_off();
	/**
	 * @brief Ignore faint text
	 * 
	 * @return style& *this
	 */
	style& faint_ignore();
	/**
	 * @brief Return the state the faint stylepoint is set to.
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state faint() const;
	/**
	 * @brief Set the state of the faint stylepoint.
	 * 
	 * @param s ON|OFF|IGNORE
	 */
	void faint(const state& s);

	/**
	 * @brief Turn italics on.
	 * 
	 * @return style& *this
	 */
	style& italic_on();
	/**
	 * @brief Turn italics off.
	 * 
	 * @return style& *this
	 */
	style& italic_off();
	/**
	 * @brief Ignore italics
	 * 
	 * @return style& *this
	 */
	style& italic_ignore();
	/**
	 * @brief Get the state italics is in.
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state italic() const;
	/**
	 * @brief Set the state italics is in.
	 * 
	 * @param s The new state of italics.
	 */
	void italic(const state& s);

	/**
	 * @brief Turn on underlining.
	 * 
	 * @return style& *this
	 */
	style& underline_on();
	/**
	 * @brief Turn off underlining.
	 * 
	 * @return style& *this
	 */
	style& underline_off();
	/**
	 * @brief Ignore underlining
	 * 
	 * @return style& *this
	 */
	style& underline_ignore();
	/**
	 * @brief Get the state of underlining
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state underline() const;
	/**
	 * @brief Set the state of underlining.
	 * 
	 * @param s ON|OFF|IGNORE
	 */
	void underline(const state& s);

	/**
	 * @brief Turn text blinking on
	 * 
	 * @return style& *this
	 */
	style& blink_on();
	/**
	 * @brief Turn text blinking off
	 * 
	 * @return style& *this
	 */
	style& blink_off();
	/**
	 * @brief Ignore blinking
	 * 
	 * @return style& *this
	 */
	style& blink_ignore();
	/**
	 * @brief Get the state of blinking
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state blink() const;
	/**
	 * @brief Set the state of blinking.
	 * 
	 * @param s ON|OFF|IGNORE
	 */
	void blink(const state& s);

	/**
	 * @brief Turn on strikeout
	 * 
	 * @return style& *this 
	 */
	style& strikeout_on();
	/**
	 * @brief Turn off strikeout
	 * 
	 * @return style& *this
	 */
	style& strikeout_off();
	/**
	 * @brief Ignore strikeout
	 * 
	 * @return style& *this
	 */
	style& strikeout_ignore();
	/**
	 * @brief Get the state of strikeout
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state strikeout() const;
	/**
	 * @brief Set the state of strikeout
	 * 
	 * @param s ON|OFF|IGNORE
	 */
	void strikeout(const state& s);

	/**
	 * @brief Set the foreground color.
	 * 
	 * @param c The foreground (text) color.
	 * @return style& *this
	 */
	style& fg_on(color c);
	/**
	 * @brief Reset foreground color
	 * 
	 * @return style& *this
	 */
	style& fg_off();
	/**
	 * @brief Ignore current foreground color
	 * 
	 * @return style& *this
	 */
	style& fg_ignore();
	/**
	 * @brief Get the state of the foreground color.
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state fg() const;
	/**
	 * @brief Get the foreground color.
	 * 
	 * @return std::optional<color> The FG color, if it's in use.
	 */
	std::optional<color> fg_color() const;
	/**
	 * @brief Set the foreground state
	 * 
	 * @param s ON|OFF|IGNORE
	 * @param c if state != ON, this param is ignored
	 */
	void fg(const state& s, color c = color());

	/**
	 * @brief Set the background color.
	 * 
	 * @param c The background color
	 * @return style& *this
	 */
	style& bg_on(color c);
	/**
	 * @brief Reset the background color
	 * 
	 * @return style& *this
	 */
	style& bg_off();
	/**
	 * @brief Ignore the background color.
	 * 
	 * @return style& *this
	 */
	style& bg_ignore();
	/**
	 * @brief Get the state of the background
	 * 
	 * @return state ON|OFF|IGNORE
	 */
	state bg() const;
	/**
	 * @brief Get the background color.
	 * 
	 * @return std::optional<color> The background color, if it's in use.
	 */
	std::optional<color> bg_color() const;
	/**
	 * @brief Set the background state
	 * 
	 * @param s ON|OFF|IGNORE
	 * @param c if state != ON, this param is ignored.
	 */
	void bg(const state& s, color c = color());

	/**
	 * @brief Turn on style resetting
	 * 
	 * @return style& *this
	 */
	style& reset_on();
	/**
	 * @brief Turn off style resetting
	 * 
	 * @return style& *this
	 */
	style& reset_off();
	/**
	 * @brief Get the state of style resetting.
	 * 
	 * @remarks Despite the misleading name, this does not reset the style. See flush().
	 * 
	 * @return state ON|OFF 
	 * 
	 * @see flush()
	 */
	state reset() const;
	/**
	 * @brief Set the state of style resetting.
	 * 
	 * @param state ON|OFF only, never IGNORE.
	 */
	void reset(const state& state);

	/**
	 * @brief Flush this style itself, clearing the ansi code and resetting all to IGNORE.
	 *  
	 */
	void flush();

	/**
	 * @brief Generates a series of ansi codes with the set stylepoints.
	 * 
	 * @return std::string A sequence of ansi escape codes to be printed to stdout, generating
	 * this style.
	 * 
	 * @remarks reset() stylepoint will always be last in the sequence.
	 */
	std::string code() const;

	/**
	 * @brief Equality overload. Compares the result of style::code().
	 * 
	 * @param other The other style.
	 * @return true If the two styles are equal.
	 */
	bool operator==(const style& other) const;

	/**
	 * @brief Inequality overload. Compares the result of style::code().
	 * 
	 * @param other The other style.
	 * @return true If the two styles are inequal.
	 */
	bool operator!=(const style& other) const;

private:
	/**
	 * @brief ANSI codes for certain text properties.
	 * 
	 */
	enum class codes : uint8_t
	{
		RESET		  = 0,
		BOLD_ON		  = 1,
		FAINT_ON	  = 2,   // not widely supported
		ITALIC_ON	 = 3,
		UNDERLINE_ON  = 4,
		BLINK_ON	  = 5,
		STRIKEOUT_ON  = 9,
		BOLD_OFF	  = 21,
		FAINT_OFF	 = 22,
		ITALIC_OFF	= 23,
		UNDERLINE_OFF = 24,
		BLINK_OFF	 = 25,
		STRIKEOUT_OFF = 29,
		FG_DEFAULT	= 39,   // Used internally
		BG_DEFAULT	= 49	// Used internally
	};

	/// The set of all styles to apply.
	std::set<codes, std::greater<codes>> m_style;
	/// True if the given code exists in m_style.
	bool has(codes code) const;
	/// Generates the ansi code => "\u001b[`code`m".
	std::string generate_ansi(codes code) const;
	/// The foreground text color.
	color m_fg;
	state m_fg_state;   // Foreground edit state.
	/// The background text color.
	color m_bg;
	state m_bg_state;   // Background edit state.
};

}

/**
 * @brief ostream overload for outputting the style code.
 * 
 */
std::ostream& operator<<(std::ostream& os, const tgfx::style& style);

/**
 * @brief Basic independent usage of tgfx::style to color and style text sent to stdout.
 * 
 * @example style/style.cpp
 * 
 */