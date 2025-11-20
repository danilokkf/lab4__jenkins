pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Ваше посилання на гіт (з подвійною рискою, як ви дали)
                git branch: 'main', url: 'https://github.com/danilokkf/lab4__jenkins.git'
            }
        }
        
        stage('Build') {
            steps {
                // ВИПРАВЛЕНО:
                // 1. Подвійні слеші (\\) у шляху.
                // 2. Команди Restore, Rebuild, Release англійською мовою.
                // Перевірте, чи у вас VS 2022 або 2019, і виправте цифру у шляху, якщо треба.
                
                bat '"C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /t:Restore;Rebuild /p:Configuration=Release'
            }
        }

        stage('Test') {
            steps {
                // Тут теж потрібні подвійні слеші
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