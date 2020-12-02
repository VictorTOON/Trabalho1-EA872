#include "axeModel.hpp"

AxeModel::AxeModel(int x, int y, float teta, int h, int w, float speed): ProjectileModel(x, y, teta, h, w, speed){
}

nlohmann::json AxeModel::getStateJson() {
	nlohmann::json stateJson;
	stateJson["base"] = this->baseJson();
	return stateJson;
}
