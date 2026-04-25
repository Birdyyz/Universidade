from abc import abstractmethod
import numpy as np
from layers import Layer

class ActivationLayer(Layer):

    def forward_propagation(self, input, training):
        self.input = input
        self.output = self.activation_function(self.input)
        return self.output

    def backward_propagation(self, output_error):
        return self.derivative(self.input) * output_error

    @abstractmethod
    def activation_function(self, input):
        raise NotImplementedError

    @abstractmethod
    def derivative(self, input):
        raise NotImplementedError

    def output_shape(self):
        return self._input_shape

    def parameters(self):
        return 0
    

class SigmoidActivation(ActivationLayer):

    def activation_function(self, input):
        # TODO 3
        #σ(x) = 1 / (1 + e^(-x))
        sigmoide = 1 / (1+ np.exp(-input))
        # Apply the sigmoid function (outputs values between 0 and 1).
        return sigmoide

    def derivative(self, input):
        sigmoide = self.activation_function(self,input)
        der = sigmoide * (1 - sigmoide)
        return der


class ReLUActivation(ActivationLayer):

    def activation_function(self, input):
        return np.maximum(0, input)

    def derivative(self, input):
        if self.activation_function(self,input) > 0:
            return 1
        return 0
