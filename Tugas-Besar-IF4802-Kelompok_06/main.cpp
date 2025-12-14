#include <iostream>
#include "Paper.h"
#include "main_admin.h"
#include "main_user.h"

using namespace std;

void initDummyData(ListPaper &L) {
    addressPaper P;
    addressKeyword K;

    InfotypePaper d1 = {"Generative_AI_Trends", "10.101/ai.2024", "Altman_S", "sam@openai", "OpenAI_Lab", 2024};
    createElementPaper(d1, P); insertLastPaper(L, P);
    createElementKeyword({"LLM", "Machine Learning", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"ChatGPT", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Python", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Transformer", "Machine Learning", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Chatbot", "Web", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d2 = {"Next_Gen_Web_Dev", "10.102/web.23", "Vercel_Team", "team@vercel", "Vercel_Inc", 2023};
    createElementPaper(d2, P); insertLastPaper(L, P);
    createElementKeyword({"NextJS", "Web", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"React", "Web", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Typescript", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Frontend", "Web", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Performance", "Tools", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d3 = {"GTA_VI_Graphics", "10.103/game.25", "Rockstar_R", "dev@rockstar", "Rockstar_North", 2025};
    createElementPaper(d3, P); insertLastPaper(L, P);
    createElementKeyword({"Ray_Tracing", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Open_World", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Unreal_Engine", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Physics", "Game", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Hype", "Entertainment", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d4 = {"Docker_Containers", "10.104/ops.19", "Solomon_H", "hykes@docker", "Docker_Inc", 2019};
    createElementPaper(d4, P); insertLastPaper(L, P);
    createElementKeyword({"Container", "Tools", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"DevOps", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Kubernetes", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Cloud", "Web", 7}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Linux", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d5 = {"Metaverse_Economy", "10.105/meta.22", "Zuck_M", "mark@meta", "Meta_Platforms", 2022};
    createElementPaper(d5, P); insertLastPaper(L, P);
    createElementKeyword({"VR", "Entertainment", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Blockchain", "Web", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Avatar", "Game", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Social", "Entertainment", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Unity", "Tools", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d6 = {"AlphaGo_Analysis", "10.106/ai.18", "DeepMind", "info@deepmind", "Google_Brain", 2018};
    createElementPaper(d6, P); insertLastPaper(L, P);
    createElementKeyword({"Reinforcement", "Machine Learning", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Go_Game", "Game", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Strategy", "Game", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Neural_Net", "Machine Learning", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Google", "Web", 6}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d7 = {"Cyberpunk_Launch", "10.107/game.20", "CD_Projekt", "red@cdpr", "CDPR_Poland", 2020};
    createElementPaper(d7, P); insertLastPaper(L, P);
    createElementKeyword({"RPG", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Bug_Fixing", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Storytelling", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"PC_Gaming", "Game", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Glitch", "Entertainment", 6}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d8 = {"NFT_Marketplace", "10.108/web.21", "Vitalik_B", "eth@foundation", "Ethereum_F", 2021};
    createElementPaper(d8, P); insertLastPaper(L, P);
    createElementKeyword({"Crypto", "Web", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Art", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Smart_Contract", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Ethereum", "Web", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Investing", "Entertainment", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d9 = {"TensorFlow_Basics", "10.109/ml.17", "Google_Dev", "tf@google", "Google_Inc", 2017};
    createElementPaper(d9, P); insertLastPaper(L, P);
    createElementKeyword({"TensorFlow", "Machine Learning", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Python", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Deep_Learning", "Machine Learning", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Data_Science", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Open_Source", "Web", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d10 = {"React_Server_Comps", "10.110/web.24", "Dan_Abramov", "dan@react", "Meta_OpenSource", 2024};
    createElementPaper(d10, P); insertLastPaper(L, P);
    createElementKeyword({"RSC", "Web", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Javascript", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Framework", "Web", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"UI_Design", "Entertainment", 6}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Optimization", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d11 = {"Baldurs_Gate_3_Des", "10.111/game.23", "Larian_S", "swen@larian", "Larian_Studios", 2023};
    createElementPaper(d11, P); insertLastPaper(L, P);
    createElementKeyword({"Turn_Based", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Dungeons_Dragons", "Entertainment", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Narrative", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Co_Op", "Game", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"C++", "Tools", 6}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d12 = {"Fortnite_Impact", "10.112/game.18", "Epic_Games", "tim@epic", "Epic_HQ", 2018};
    createElementPaper(d12, P); insertLastPaper(L, P);
    createElementKeyword({"Battle_Royale", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Streaming", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Unreal_Engine", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Multiplayer", "Game", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Esports", "Entertainment", 8}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d13 = {"Stable_Diffusion", "10.113/ml.22", "Stability_AI", "info@stability", "Stability_Lab", 2022};
    createElementPaper(d13, P); insertLastPaper(L, P);
    createElementKeyword({"Image_Gen", "Machine Learning", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Art_AI", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"GPU_Computing", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Python", "Tools", 7}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Prompting", "Web", 8}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d14 = {"Zoom_Architecture", "10.114/web.20", "Eric_Yuan", "eric@zoom", "Zoom_Video", 2020};
    createElementPaper(d14, P); insertLastPaper(L, P);
    createElementKeyword({"Video_Call", "Web", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Streaming", "Web", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Remote_Work", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Server", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Communication", "Entertainment", 6}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d15 = {"Quantum_Web", "10.115/web.25", "IBM_Research", "lab@ibm", "IBM_Q", 2025};
    createElementPaper(d15, P); insertLastPaper(L, P);
    createElementKeyword({"Quantum", "Tools", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Cryptography", "Web", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Future_Tech", "Machine Learning", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Security", "Web", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Physics", "Tools", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d16 = {"Switch_Console", "10.116/game.17", "Nintendo", "mario@nintendo", "Nintendo_JP", 2017};
    createElementPaper(d16, P); insertLastPaper(L, P);
    createElementKeyword({"Hybrid_Console", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Zelda", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Portable", "Tools", 7}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Hardware", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Family", "Entertainment", 8}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d17 = {"Github_Copilot", "10.117/ai.21", "Github_Team", "support@github", "Microsoft", 2021};
    createElementPaper(d17, P); insertLastPaper(L, P);
    createElementKeyword({"Coding_AI", "Machine Learning", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Productivity", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"VS_Code", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"OpenAI_Codex", "Machine Learning", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Programming", "Web", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d18 = {"Tiktok_Algorithm", "10.118/ent.19", "ByteDance", "algo@tiktok", "ByteDance_CN", 2019};
    createElementPaper(d18, P); insertLastPaper(L, P);
    createElementKeyword({"Recommendation", "Machine Learning", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Short_Video", "Entertainment", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Viral", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Mobile_App", "Web", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Data_Mining", "Tools", 7}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d19 = {"Vision_Pro_UX", "10.119/tools.24", "Apple_Design", "design@apple", "Apple_Park", 2024};
    createElementPaper(d19, P); insertLastPaper(L, P);
    createElementKeyword({"Spatial_Comp", "Tools", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"AR_VR", "Game", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"UX_Design", "Web", 7}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Hardware", "Tools", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Movies", "Entertainment", 8}, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d20 = {"Red_Dead_2_Tech", "10.120/game.18", "Rockstar_SD", "dev@rdr2", "Rockstar_SanDiego", 2018};
    createElementPaper(d20, P); insertLastPaper(L, P);
    createElementKeyword({"Open_World", "Game", 10}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Realism", "Tools", 8}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Western", "Entertainment", 9}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"AI_NPC", "Machine Learning", 7}, K); insertLastKeyword(P->firstKeyword, K);
    createElementKeyword({"Visuals", "Game", 9}, K); insertLastKeyword(P->firstKeyword, K);

    cout << "[DEBUG] 20 Data Dummy Berhasil Dimuat!" << endl;
}

int main()
{
    ListPaper ListAdmin;
    createListPaper(ListAdmin);

    ListPaper ListUser;
    createListPaper(ListUser);
    initDummyData(ListUser);

    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ MAIN MENU ============" << endl;
        cout << "|| 1. Admin                      ||" << endl;
        cout << "|| 2. User                       ||" << endl;
        cout << "|| 0. Exit                       ||" << endl;
        cout << "===================================" << endl;
        cout << "Pilihan: ";
        cin >> option;

        switch(option) {
            case 1:
                menuAdmin(ListAdmin);
                break;
            case 2:
                menuUser(ListUser);
                break;
            case 0:
                cout << "Keluar program..." << endl;
                break;
            default:
                cout << "Pilihan salah." << endl;
                cin.ignore(); cin.get();
        }
    }
    return 0;
}
