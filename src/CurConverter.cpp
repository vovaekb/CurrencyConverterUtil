#include <iostream>
#include <fmt/core.h>
#include <fmt/format.h>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <CurConverter.h>


using json = nlohmann::json;

CurConverter::CurConverter(std::string apiKey) : m_apiKey(apiKey)
{
    m_domainUrl = "https://api.fastforex.io/";
}

CurConverter::~CurConverter()
{
}

float CurConverter::getRate(std::string curFrom, std::string curTo)
{
    std::string reqUrl = fmt::format("{}/fetch-one?from={}&to={}&api_key={}", m_domainUrl, curFrom, curTo, m_apiKey);
    std::cout << reqUrl << std::endl;

    std::cout << "Line 22\n";

    auto res = cpr::Get(cpr::Url{reqUrl});
    std::cout << "Line 23\n";
    if (res.error)
    {
        std::cout << "Network error\n";
    }
    if (res.status_code != 200)
    {
        std::cout << "HTTP error:" << res.status_code << "\n";
    }
    else
    {
        std::cout << "Request success\n";

        auto resData = json::parse(res.text);

        for (const auto& [key, value] : resData.items())
        {
            std::cout << "key: " << key << "\n";
        }
    }
    std::cout << "res.status_code:" << res.status_code << "\n";
    
}