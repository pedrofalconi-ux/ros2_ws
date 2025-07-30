from setuptools import find_packages
from setuptools import setup

setup(
    name='robot_ras_decision',
    version='0.0.1',
    packages=find_packages(
        include=('robot_ras_decision', 'robot_ras_decision.*')),
)
