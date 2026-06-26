#pragma once

namespace SGELProdAutomModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class TipoRobot {
    protected:
		int idTipoRobot;
        String^ tipoRobot;

    public:
        TipoRobot();
        TipoRobot(int id, String^ tipoRobot);

		int getIdTipoRobot();
		void setIdTipoRobot(int id);

        String^ getTipoRobot();
        void setTipoRobot(String^ tipoRobot);
    };
}