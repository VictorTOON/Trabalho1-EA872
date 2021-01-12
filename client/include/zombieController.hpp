#pragma once
#include "zombieModel.hpp"
#include "characterModel.hpp"

#include "json.hpp"
#include <string>

static int ID_CONTROLLER = 0;

class ZumbiController {
	private:
		ZumbiModel model;
		int id;
        std::string player_id;
	public: 
        /* \brief Contrutor do ZumbiController
            *
            * \param x posição em x
            * \param y posição em y
            * \param teta angulo do zumbi
            * \param h altura do frame do zumbi
            * \param w largura do frame do zumbi
            * \param player_id player que o zumbi está focando
            * */
		ZumbiController(int x, int y, int h, int w, float teta, std::string player_id);
        /* \brief UpdateModel
            *Atualiza o modelo do zumbi para se mover em direção a player
            *
            * */
		void updateModel(std::shared_ptr<PersonagemModel> p);
		ZumbiModel getModel();
        /* \brief iterate
            *Roda várias rodadas de update dos zumbis
            *
            * */
		void iterate(std::shared_ptr<PersonagemModel> p);
		ZumbiModel get_model();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		void saveStateJson();
		std::string get_id(); 
		void set_player_id(std::string player_id);
        std::string get_player_id();
};
