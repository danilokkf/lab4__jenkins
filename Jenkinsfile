pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/danilokkf/lab4__jenkins.git'
            }
        }
        
        stage('Build') {
            steps {
                // ДОДАНО: /p:RestorePackagesConfig=true
                // Це змушує MSBuild завантажити відсутні бібліотеки (GoogleTest)
                // УВАГА: Залиште той шлях, який у вас спрацював (з цифрою 18 або 2022)
                
                bat '"C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /t:Restore;Rebuild /p:RestorePackagesConfig=true;Configuration=Release'
            }
        }

        stage('Test') {
            steps {
                bat 'x64\\Release\\test_repos.exe --gtest_output=xml:test_report.xml'
            }
        }
    }

    post {
        always {
            junit 'test_report.xml'
        }
    }
}