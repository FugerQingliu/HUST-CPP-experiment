#include "CmderFactory.hpp"

namespace adas
{
    CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept
    {
        CmderList cmderList;
        for (const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end())
            {
                cmderList.push_back(it->second);
            }
        }
        return cmderList;
    }
}