#pragma once

#include "MultiLayerPerceptron.h"

namespace WhydahGally
{
	namespace Base
	{
		class MLPFast : public MultiLayerPerceptron
		{
		//Faster version of the MLP; it is faster thanks to the use of the matrices instead of the 2D vectors for the computations.
		private:
			std::vector<Matrix> weightsF_;
			std::vector<Matrix> layersF_;
			std::vector<Matrix> layerDeltaUseF_;

		private:
			void calculateLayers(const int& parall);
			void computeErrors(const int& counter, const int& lossFunction, const bool& plot, const bool& backpropagation, const int& parall);
			
		public:
			MLPFast(Importer& importer, const float& limMin, const float& limMax, const float& seedNo, int numNeurArr[12]);
			~MLPFast();

			void train() override;
			void train(DistribParamForMLP& distrParam, int ranges[3], int checkPoints[3], const int& lossFunction, const bool& plot, const bool& print, const int& parall);
		};
	}
}





