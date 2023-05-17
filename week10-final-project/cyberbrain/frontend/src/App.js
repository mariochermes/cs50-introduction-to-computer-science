import { BrowserRouter , Routes, Route } from 'react-router-dom';
import Layout from './Layout';
import HomePage from './pages/HomePage';
import TasksPage from './pages/TasksPage';
import AreasPage from './pages/AreasPage';
import ResourcesPage from './pages/ResourcesPage';
import ArchivesPage from './pages/ArchivesPage';


export default function App() {
  return (
    <>
      <BrowserRouter>
        <Layout>
          <Routes>
            <Route path="/" element={<HomePage />} />
            <Route path="/tasks" element={<TasksPage />} />
            <Route path="/areas" element={<AreasPage />} />
            <Route path="/resources" element={<ResourcesPage />} />
            <Route path="/archives" element={<ArchivesPage />} />
          </Routes>
        </Layout>
      </BrowserRouter>
    </>
  );
}
