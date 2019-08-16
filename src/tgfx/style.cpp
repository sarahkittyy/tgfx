#include <algorithm>
#include <sstream>
#include "tgfx/style.hpp"

namespace tgfx
{

style::style()
	: m_fg(0),
	  m_fg_state(state::IGNORE),
	  m_bg(0),
	  m_bg_state(state::IGNORE)
{
}

bool style::has(codes code) const
{
	return m_style.find(code) != m_style.end();
}

void style::flush()
{
	m_style.clear();
	m_bg_state = state::IGNORE;
	m_fg_state = state::IGNORE;
}

std::string style::code() const
{
	std::ostringstream ss;

	// Color states
	if (m_fg_state == state::ON)
		ss << m_fg.to_ansi_escape(true);
	if (m_bg_state == state::ON)
		ss << m_bg.to_ansi_escape(false);

	// Stylepoint escapes.
	for (const codes& code : m_style)
	{
		// Push the ansi code for each stylepoint.
		ss << generate_ansi(code);
	}
	return ss.str();
}

/**
 * @brief This macro reduces boilerplate for the standard style functions
 * on, off, ignore, and state setters / getters.
 * 
 */
#define GEN_STYLE(lower, upper)             \
	style& style::lower##_on()              \
	{                                       \
		m_style.erase(codes::upper##_OFF);  \
		m_style.insert(codes::upper##_ON);  \
		return *this;                       \
	}                                       \
	style& style::lower##_off()             \
	{                                       \
		m_style.erase(codes::upper##_ON);   \
		m_style.insert(codes::upper##_OFF); \
		return *this;                       \
	}                                       \
	style& style::lower##_ignore()          \
	{                                       \
		m_style.erase(codes::upper##_ON);   \
		m_style.erase(codes::upper##_OFF);  \
		return *this;                       \
	}                                       \
	style::state style::lower() const       \
	{                                       \
		if (has(codes::upper##_ON))         \
		{                                   \
			return state::ON;               \
		}                                   \
		else if (has(codes::upper##_OFF))   \
		{                                   \
			return state::OFF;              \
		}                                   \
		else                                \
		{                                   \
			return state::IGNORE;           \
		}                                   \
	}                                       \
	void style::lower(const state& s)       \
	{                                       \
		if (s == state::ON)                 \
		{                                   \
			lower##_on();                   \
		}                                   \
		else if (s == state::OFF)           \
		{                                   \
			lower##_off();                  \
		}                                   \
		else                                \
		{                                   \
			lower##_ignore();               \
		}                                   \
	}

GEN_STYLE(bold, BOLD)
GEN_STYLE(faint, FAINT)
GEN_STYLE(italic, ITALIC)
GEN_STYLE(underline, UNDERLINE)
GEN_STYLE(blink, BLINK)
GEN_STYLE(strikeout, STRIKEOUT)

style& style::reset_on()
{
	m_style.insert(codes::RESET);
	return *this;
}

style& style::reset_off()
{
	m_style.erase(codes::RESET);
	return *this;
}

style::state style::reset() const
{
	if (has(codes::RESET))
		return state::ON;
	else
		return state::OFF;
}

void style::reset(const state& state)
{
	if (state == state::ON)
		m_style.insert(codes::RESET);
	else
		m_style.erase(codes::RESET);
}

style& style::fg_on(color c)
{
	m_fg_state = state::ON;
	m_fg	   = c;
	return *this;
}

style& style::fg_off()
{
	m_fg_state = state::OFF;
	return *this;
}

style& style::fg_ignore()
{
	m_fg_state = state::IGNORE;
	return *this;
}

style::state style::fg() const
{
	return m_fg_state;
}

std::optional<color> style::fg_color() const
{
	if (m_fg_state != state::ON)
		return {};
	else
		return m_fg;
}

void style::fg(const state& s, color c)
{
	m_fg_state = s;
	m_fg	   = c;
}

style& style::bg_on(color c)
{
	m_bg_state = state::ON;
	m_bg	   = c;
	return *this;
}

style& style::bg_off()
{
	m_bg_state = state::OFF;
	return *this;
}

style& style::bg_ignore()
{
	m_bg_state = state::IGNORE;
	return *this;
}

style::state style::bg() const
{
	return m_bg_state;
}

std::optional<color> style::bg_color() const
{
	if (m_bg_state != state::ON)
		return {};
	else
		return m_bg;
}

void style::bg(const state& s, color c)
{
	m_bg_state = s;
	m_bg	   = c;
}

std::string style::generate_ansi(codes code) const
{
	// Output string stream.
	std::ostringstream ss;
	ss << "\u001b[" << static_cast<int>(code) << "m";
	return ss.str();
}

}