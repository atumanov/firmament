// The Firmament project
// Copyright (c) 2015 Ionel Gog <ionel.gog@cl.cam.ac.uk>

#include "scheduling/octopus_cost_model.h"

namespace firmament {

OctopusCostModel::OctopusCostModel() {
}

Cost_t OctopusCostModel::TaskToUnscheduledAggCost(TaskID_t task_id) {
  return 0LL;
}

Cost_t OctopusCostModel::UnscheduledAggToSinkCost(JobID_t job_id) {
  return 0LL;
}

Cost_t OctopusCostModel::TaskToClusterAggCost(TaskID_t task_id) {
  return 0LL;
}

Cost_t OctopusCostModel::TaskToResourceNodeCost(TaskID_t task_id,
                                                ResourceID_t resource_id) {
  return 0LL;
}

Cost_t OctopusCostModel::ResourceNodeToResourceNodeCost(
    ResourceID_t source,
    ResourceID_t destination) {
  return 0LL;
}

Cost_t OctopusCostModel::LeafResourceNodeToSinkCost(ResourceID_t resource_id) {
  return 0LL;
}

Cost_t OctopusCostModel::TaskContinuationCost(TaskID_t task_id) {
  return 0ULL;
}

Cost_t OctopusCostModel::TaskPreemptionCost(TaskID_t task_id) {
  return 0ULL;
}

Cost_t OctopusCostModel::TaskToEquivClassAggregator(TaskID_t task_id,
                                                    EquivClass_t tec) {
  return 0ULL;
}

Cost_t OctopusCostModel::EquivClassToResourceNode(EquivClass_t tec,
                                                  ResourceID_t res_id) {
  return 0ULL;
}

Cost_t OctopusCostModel::EquivClassToEquivClass(EquivClass_t tec1,
                                                EquivClass_t tec2) {
  return 0LL;
}

vector<EquivClass_t>* OctopusCostModel::GetTaskEquivClasses(
    TaskID_t task_id) {
  vector<EquivClass_t>* equiv_classes = new vector<EquivClass_t>();
  // TaskDescriptor* td_ptr = FindPtrOrNull(*task_map_, task_id);
  // CHECK_NOTNULL(td_ptr);
  // // A level 0 TEC is the hash of the task binary name.
  // size_t hash = 0;
  // boost::hash_combine(hash, td_ptr->binary());
  // equiv_classes->push_back(static_cast<EquivClass_t>(hash));
  return equiv_classes;
}

vector<EquivClass_t>* OctopusCostModel::GetResourceEquivClasses(
    ResourceID_t res_id) {
  vector<EquivClass_t>* equiv_classes = new vector<EquivClass_t>();
  return equiv_classes;
}

vector<ResourceID_t>* OctopusCostModel::GetOutgoingEquivClassPrefArcs(
    EquivClass_t tec) {
  vector<ResourceID_t>* prefered_res = new vector<ResourceID_t>();
  return prefered_res;
}

vector<TaskID_t>* OctopusCostModel::GetIncomingEquivClassPrefArcs(
    EquivClass_t tec) {
  vector<TaskID_t>* prefered_tasks = new vector<TaskID_t>();
  return prefered_tasks;
}

vector<ResourceID_t>* OctopusCostModel::GetTaskPreferenceArcs(
    TaskID_t task_id) {
  vector<ResourceID_t>* prefered_res = new vector<ResourceID_t>();
  return prefered_res;
}

pair<vector<EquivClass_t>*, vector<EquivClass_t>*>
    OctopusCostModel::GetEquivClassToEquivClassesArcs(EquivClass_t tec) {
  vector<EquivClass_t>* equiv_classes = new vector<EquivClass_t>();
  return pair<vector<EquivClass_t>*,
              vector<EquivClass_t>*>(equiv_classes, equiv_classes);
}

void OctopusCostModel::AddMachine(
    const ResourceTopologyNodeDescriptor* rtnd_ptr) {
}

void OctopusCostModel::RemoveMachine(ResourceID_t res_id) {
}

void OctopusCostModel::RemoveTask(TaskID_t task_id) {
}

}  // namespace firmament
