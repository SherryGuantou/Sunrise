#pragma once

namespace Resource
{
const std::string Dir = "/";
const std::string Version = "1.0.0";
const std::string Author = "SherryGuantou & DiedRadish";

namespace Assets
{
const std::string Dir = Resource::Dir + "Assets/";
namespace Fonts
{
const std::string Dir = Resource::Assets::Dir + "Fonts/";
const std::string Consola = Dir + "Consola.ttf";
const std::string Kai = Dir + "KaiSim.ttf";
const std::string Msyh = Dir + "Msyh.ttc";
const std::string MsyhB = Dir + "MsyhB.ttc";
const std::string MsyhL = Dir + "MsyhL.ttc";
}
namespace Images
{
const std::string Dir = Resource::Assets::Dir + "Images/";
const std::string BackGround = Dir + "BackGround.png";
const std::string BattleBG = Dir + "BattleBG.jpg";
const std::string ButtonDisable = Dir + "Button_Disable.png";
const std::string ButtonNormal = Dir + "Button_Normal.png";
const std::string ButtonPress = Dir + "Button_Press.png";
const std::string Defeat = Dir + "Defeat.jpg";
const std::string Success = Dir + "Success.jfif";
}
}
namespace Config
{
const std::string Dir = Resource::Dir + "Config/";
const std::string Levels = Dir + "Levels.json";
const std::string Saves = Dir + "Saves.json";
const std::string LevelData = Dir + "LevelData.json";
}
}