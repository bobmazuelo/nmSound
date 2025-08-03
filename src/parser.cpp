/**
 * @file parser.cpp
 * @brief Simple line parser for the mmsound tool.
 *
 * This parser currently handles a minimal subset of the expected grammar.
 * Supported constructs include:
 *   - Tempo directives in the form `T<value>`
 *   - Default length directives `L<value>`
 *   - Individual musical notes separated by whitespace
 *
 * Anything outside of these patterns results in a runtime_error which is
 * expected to be handled by the caller.
 */

#include <mmsound.h>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

// Default note length (quarter note by default)
unsigned int g_default_long = 4;

/**
 * @brief Trim whitespace from both ends of the given string.
 */
static void trim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

/**
 * @brief Parse a single line of mmsound input.
 *
 * Lines may include comments starting with "//".  Recognised directives are
 * emitted to stdout so the caller can react accordingly.  A syntax error in any
 * token throws a std::runtime_error.
 *
 * @param line Line of text to parse.
 */
void parser_mmline(std::string &line)
{
    // Remove comments
    line = std::regex_replace(line, std::regex("//.*"), "");
    trim(line);

    if (line.empty())
        return; // Nothing to parse

    std::smatch match;

    // Tempo directive
    if (std::regex_match(line, match, std::regex("^T\\s*([0-9]+)$", std::regex::icase)))
    {
        std::cout << "[TEMPO] " << match[1] << std::endl;
        return;
    }

    // Default length directive
    if (std::regex_match(line, match, std::regex("^L\\s*([0-9]+)$", std::regex::icase)))
    {
        g_default_long = std::stoul(match[1]);
        std::cout << "[LENGTH] " << g_default_long << std::endl;
        return;
    }

    // Otherwise parse notes separated by whitespace
    std::stringstream ss(line);
    std::string token;
    std::regex note_re("^[a-gA-G][#\\+\\-b]?\\d*\\.?$");

    while (ss >> token)
    {
        if (!std::regex_match(token, note_re))
            throw std::runtime_error("Syntax file error.");

        std::cout << "[NOTE] " << token << std::endl;
    }
}

