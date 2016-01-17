#include "layer\SGDSolver.h"

SGDSolver::SGDSolver(double regularizationRate, double weightLearningRate, double biasLearningRate, double momentumRate)
:Solver(regularizationRate,weightLearningRate, biasLearningRate, momentumRate){

}

void SGDSolver::update(vector<vector<shared_ptr<Matrix>>> convKernels, vector<vector<shared_ptr<Matrix>>> convKernelMomentum,
	vector<vector<shared_ptr<Matrix>>> convKernelsGradient, vector<shared_ptr<Matrix>> bias,
	vector<shared_ptr<Matrix>> biasMomentum, vector<shared_ptr<Matrix>> biasGradient, int num){

	for (int i = 0; i < num; i++)
	{
		for (size_t j = 0; j < num; j++)
		{
			convKernelMomentum[i][j]->muli(momentumRate);
			convKernelMomentum[i][j]->addi(convKernelsGradient[i][j]);
			convKernelMomentum[i][j]->subi(convKernels[i][j]->mul(regularizationRate));
			convKernels[i][j]->addi(convKernelMomentum[i][j]->mul(weightLearningRate));
			convKernelsGradient[i][j]->setValues(0);
		}
		biasMomentum[i][j]->muli(momentumRate);
		biasMomentum[i][j]->addi(biasGradient[i][j]);
		biasMomentum[i][j]->subi(bias[i][j]->mul(regularizationRate));
		bias[i][j]->addi(biasMomentum[i][j]->mul(biasLearningRate));
		biasGradient[i]->setValues(0);
	}
	
}

void SGDSolver::update(shared_ptr<Matrix> weight, shared_ptr<Matrix> weightMomentum, shared_ptr<Matrix> weightGradient,
	shared_ptr<Matrix> bias, shared_ptr<Matrix> biasMomentum, shared_ptr<Matrix> biasGradient, int num){

	weightMomentum->muli(momentumRate);
	weightMomentum->addi(weightGradient);
	weightMomentum->subi(weight->mul(regularizationRate));
	weight->addi(weightMomentum->mul(weightLearningRate));

	biasMomentum->muli(momentumRate);
	biasMomentum->addi(biasGradient);
	biasMomentum->subi(bias->mul(regularizationRate));
	bias->addi(biasMomentum->mul(biasLearningRate));

	weightGradient->setValues(0);
	biasGradient->setValues(0);

}