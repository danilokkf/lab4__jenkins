pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Посилання на ваш репозиторій (це вірно)
                git branch: 'main', url: 'https://github.com/danilokkf/lab4__jenkins.git'
            }
        }
        
        stage('Build') {
            steps {
                // УВАГА: Замість шляху нижче, ВСТАВТЕ ТОЙ, ЯКИЙ ВИ СКОПІЮВАЛИ В ЕТАПІ 2!
                // Але замініть один слеш \ на два \\
                // Приклад: "C:\\Program Files\\..."
                
                bat '"C:\Program Files\Microsoft Visual Studio\18\Community\MSBuild\Current\Bin\MSBuild.exe" test_repos.sln /t:Restore;Rebuild /p:Configuration=Release'
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