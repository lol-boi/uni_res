import numpy as np
import gym
from gym.envs.registration import register
import random
import argparse

class Environment():
    def __init__(self):
        pass
    def FrozenLakeNoSlippery(self):
        register( id = "FrozenLakeNoSlippery-v0",
                entry_point = 'gym.envs.toy_text:FrozenLakeEnv',
                 kwargs={'map_name': '4x4', 'is_slippery': False},
                 max_episode_steps = 100, reward_threshold = 0.82)
        env = gym.make('FrozenLakeNoSlippery-v0')
        return env 
        
class QAgent():
    def __init__(self):
        # set hyperparameters
        self.max_episodes = 20000   # set max training episodes
        self.max_actions = 99       # set max actions per episodes
        self.learning_rate = 0.83   # for q-learning
        self.discount = 0.93        # for q-learning
        self.exploration_rate = 1.0 # for exploration
        self.exploration_decay = 1.0/args.max_episodes  # for exploitation

        # get environmnet
        self.env = env

        # initialize Q(s, a)
        row = env.observation_space.n # Discrete(16)
        col = env.action_space.n # Discrete(4)
        self.Q = np.zeros((row, col))
        # setting hyper-parameters and initialize Q-table
    
    def _policy(self, mode, state, e_rate):
        # return the action the Agent taken in a given state
        if mode == 'train':
            if random.random() > e_rate:
                return np.argmax(self.Q[state,:])
            else:
                return self.env.action_space.sample()
        elif mode == 'test':
            return np.argmax(self.Q[state,:])
    
    def train(self):
        # training the agent
        # get hyper-parameters
        max_episodes = self.max_episodes
        max_actions = self.max_actions
        learning_rate = self.learning_rate
        discount = self.discount
        exploration_rate = self.exploration_rate
        exploration_decay = 1.0/self.max_episodes
        
        # start training
        for i in range(max_episodes):
            state = self.env.reset() # reset the environment per eisodes
            for a in range(max_actions):
                action = self._policy('train', state, exploration_rate)
                new_state, reward, done, info = self.env.step(action)
                # The formulation of updating Q(s, a)
                self.Q[state, action] = self.Q [state, action] + learning_rate*(reward+discount*np.max(self.Q [new_state, :]) - self.Q [state, action])
                state = new_state # update the current state
                if done == True:  # if fall in the hole or arrive to the goal, then this episode is terminated.
                    break
            if exploration_rate>0.001:
                exploration_rate -= exploration_decay

    def test(self):
        # Setting hyper-parameters
        max_actions = self.max_actions
        state = self.env.reset() # reset the environment
        for a in range(max_actions):
            self.env.render() # show the environment states
            action = np.argmax(self.Q[state,:]) # take action with the Optimal Policy
            new_state, reward, done, info = self.env.step(action) # arrive to next_state after taking the action
            state = new_state # update current state
            if done:
                print("======")
                self.env.render()
                break
            print("======")
        self.env.close()

if __name__ == "__main__":
    env = Environment().FrozenLakeNoSlippery()
    agent = QAgent(args,env)
    agent.train()
    print("Testing Model")
    agent.test()
    
