def solution(id_list, report, k):
    answer = []
    report_cnt = {}
    report_history = {}
    banned_user = []
    
    for i in id_list:
        report_cnt[i] = 0
        report_history[i] = []

    for i in range(len(report)):
        splited = report[i].split()
        if splited[1] not in report_history[splited[0]]:
            report_history[splited[0]].append(splited[1])
            report_cnt[splited[1]] += 1

    for i in id_list:
        if report_cnt[i] >= k:
            banned_user.append(i)
    
    for i in range(len(id_list)):
        answer.append(0)
        for j in range(len(report_history[id_list[i]])):
            if report_history[id_list[i]][j] in banned_user:
                answer[i] += 1
    
    return answer
