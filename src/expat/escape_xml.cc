/** Copyright 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018 Roland Olbricht et al.
 *
 * This file is part of Overpass_API.
 *
 * Overpass_API is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Overpass_API is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with Overpass_API.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>

#include "escape_xml.h"


std::string escape_xml(const std::string& s)
{
  const char* digit = "0123456789abcdef";

  std::string result;
  result.reserve(s.length()*2);
  for (std::string::size_type i(0); i < s.size(); ++i)
  {
    if (s[i] == '&')
      result += "&amp;";
    else if (s[i] == '\"')
      result += "&quot;";
    else if (s[i] == '<')
      result += "&lt;";
    else if (s[i] == '>')
      result += "&gt;";
    else if ((unsigned char)s[i] < 32)
    {
      if ((s[i] == '\n') || (s[i] == '\t') || (s[i] == '\r'))
	result += std::string("&#x") + digit[s[i] / 16] + digit[s[i] % 16] + ';';
      else
        result += '?';
    }
    else
      result += s[i];
  }
  return result;
}
