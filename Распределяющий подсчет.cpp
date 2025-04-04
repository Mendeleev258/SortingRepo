void countingSort2(int* array, int n, int min, int max) {
    int* count = new int[max - min + 1];                        // Âñïîìîãàòåëüíûé ìàññèâ äëÿ ïîäñ÷åòà

    for (int i = 0; i <= max - min; i++) {                      // Èíèöèàëèçàöèÿ âñïîìîãàòåëüíîãî ìàññèâà íóëÿìè
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {                               // Ïîäñ÷åò êîëè÷åñòâà âõîæäåíèé êàæäîãî ýëåìåíòà
        count[array[i] - min]++;
    }

    for (int i = 1; i <= max - min; i++) {                      // Âû÷èñëåíèå íàêîïëåííûõ ñóìì äëÿ ïîçèöèîíèðîâàíèÿ ýëåìåíòîâ
        count[i] += count[i - 1];
    }

    int* output = new int[n];                                   // Ñîðòèðîâêà
    for (int i = 0; i < n; ++i) {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    for (int i = 0; i < n; ++i) {                               // Êîïèðîâàíèå â èñõîäíûé ìàññèâ
        array[i] = output[i];
    }

    delete[] count;
    delete[] output;
}